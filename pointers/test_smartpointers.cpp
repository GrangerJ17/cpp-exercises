 #include "Smartpointers.h"
#include <gtest/gtest.h>
#include <type_traits>
#include <utility>

namespace {

struct Tracked {
    static inline int alive = 0;
    int v;
    explicit Tracked(int x = 0) : v(x) { ++alive; }
    ~Tracked() { --alive; }
};

class UniquePtrTest : public ::testing::Test {
  protected:
    void SetUp() override { Tracked::alive = 0; }
    void TearDown() override { EXPECT_EQ(Tracked::alive, 0) << "leak or double free"; }
};

} // namespace

// --- type requirements -------------------------------------------------

static_assert(!std::is_copy_constructible_v<uniquePtr<int>>);
static_assert(!std::is_copy_assignable_v<uniquePtr<int>>);
static_assert(std::is_move_constructible_v<uniquePtr<int>>);
static_assert(std::is_move_assignable_v<uniquePtr<int>>);
static_assert(std::is_nothrow_move_constructible_v<uniquePtr<int>>);
static_assert(sizeof(uniquePtr<int>) == sizeof(int*), "must be zero-overhead");
// not implicitly constructible from a raw pointer
static_assert(!std::is_convertible_v<int*, uniquePtr<int>>);

// --- construction / destruction ---------------------------------------

TEST_F(UniquePtrTest, DefaultIsEmpty) {
    uniquePtr<Tracked> p;
    EXPECT_EQ(p.get(), nullptr);
}

TEST_F(UniquePtrTest, TakesOwnership) {
    { uniquePtr<Tracked> p(new Tracked(7));
      ASSERT_NE(p.get(), nullptr);
      EXPECT_EQ(Tracked::alive, 1);
      EXPECT_EQ(p->v, 7);
      EXPECT_EQ((*p).v, 7); }
    EXPECT_EQ(Tracked::alive, 0);
}

TEST_F(UniquePtrTest, DestroyingEmptyIsSafe) {
    { uniquePtr<Tracked> p(nullptr); }
    SUCCEED();
}

// --- release / reset ---------------------------------------------------

TEST_F(UniquePtrTest, ReleaseYieldsPointerAndClears) {
    uniquePtr<Tracked> p(new Tracked(1));
    Tracked* raw = p.release();
    EXPECT_EQ(p.get(), nullptr);
    ASSERT_NE(raw, nullptr);
    EXPECT_EQ(Tracked::alive, 1);
    delete raw;
}

TEST_F(UniquePtrTest, ResetDeletesOld) {
    uniquePtr<Tracked> p(new Tracked(1));
    p.reset(new Tracked(2));
    EXPECT_EQ(Tracked::alive, 1);
    EXPECT_EQ(p->v, 2);
}

// catches: `if (data && oldPtr) delete oldPtr;`
TEST_F(UniquePtrTest, ResetToNullFreesOld) {
    uniquePtr<Tracked> p(new Tracked(1));
    p.reset(nullptr);
    EXPECT_EQ(p.get(), nullptr);
    EXPECT_EQ(Tracked::alive, 0);
}

// catches: `reset(T* ptr = new T())`
TEST_F(UniquePtrTest, DefaultResetAllocatesNothing) {
    uniquePtr<Tracked> p(new Tracked(1));
    p.reset();
    EXPECT_EQ(p.get(), nullptr);
    EXPECT_EQ(Tracked::alive, 0);
}

TEST_F(UniquePtrTest, ResetOnEmptyIsSafe) {
    uniquePtr<Tracked> p;
    p.reset(new Tracked(3));
    EXPECT_EQ(Tracked::alive, 1);
    EXPECT_EQ(p->v, 3);
}

// --- move semantics ----------------------------------------------------

TEST_F(UniquePtrTest, MoveConstructTransfers) {
    uniquePtr<Tracked> a(new Tracked(5));
    Tracked* raw = a.get();
    uniquePtr<Tracked> b(std::move(a));
    EXPECT_EQ(a.get(), nullptr);
    EXPECT_EQ(b.get(), raw);
    EXPECT_EQ(Tracked::alive, 1);
}

TEST_F(UniquePtrTest, MoveAssignTransfersAndFreesTarget) {
    uniquePtr<Tracked> a(new Tracked(1));
    uniquePtr<Tracked> b(new Tracked(2));
    b = std::move(a);
    EXPECT_EQ(a.get(), nullptr);
    ASSERT_NE(b.get(), nullptr);
    EXPECT_EQ(b->v, 1);
    EXPECT_EQ(Tracked::alive, 1) << "target's old object should be destroyed";
}

// catches missing self-assignment guard
TEST_F(UniquePtrTest, SelfMoveAssignDoesNotDestroy) {
    uniquePtr<Tracked> p(new Tracked(9));
    p = std::move(p);
    ASSERT_NE(p.get(), nullptr);
    EXPECT_EQ(p->v, 9);
    EXPECT_EQ(Tracked::alive, 1);
}

TEST_F(UniquePtrTest, MoveAssignFromEmpty) {
    uniquePtr<Tracked> a;
    uniquePtr<Tracked> b(new Tracked(4));
    b = std::move(a);
    EXPECT_EQ(b.get(), nullptr);
    EXPECT_EQ(Tracked::alive, 0);
}

// --- swap --------------------------------------------------------------

TEST_F(UniquePtrTest, SwapExchangesOwnership) {
    uniquePtr<Tracked> a(new Tracked(1));
    uniquePtr<Tracked> b(new Tracked(2));
    a.swap(b);
    EXPECT_EQ(a->v, 2);
    EXPECT_EQ(b->v, 1);
    EXPECT_EQ(Tracked::alive, 2);
}

// --- factory -----------------------------------------------------------

struct TwoArgs {
    int a; double b;
    TwoArgs(int x, double y) : a(x), b(y) {}
};

TEST_F(UniquePtrTest, MakeUniqueForwardsArgs) {
    auto p = makeUnique<TwoArgs>(3, 1.5);
    ASSERT_NE(p.get(), nullptr);
    EXPECT_EQ(p->a, 3);
    EXPECT_DOUBLE_EQ(p->b, 1.5);
}

TEST_F(UniquePtrTest, MakeUniqueMovesRvalue) {
    struct MoveOnly {
        int v;
        explicit MoveOnly(int x) : v(x) {}
        MoveOnly(MoveOnly&&) = default;
        MoveOnly(const MoveOnly&) = delete;
    };
    auto p = makeUnique<MoveOnly>(MoveOnly{42});
    EXPECT_EQ(p->v, 42);
}
