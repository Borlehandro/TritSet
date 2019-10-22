#include "gtest/gtest.h"
#include "../src/TritSet.h"

TEST(MemoryTests, ConstructorAllocationTest) {

    for (int i=0; i<=1000; ++i) {
        TritSet set(i);

        size_t allocLength = set.capacity();
        EXPECT_GE(allocLength, i * 2 / 8 / sizeof(unsigned int));
    }
}

TEST(MemoryTests, UnknownOutOfBound) {

    TritSet set(1000);
    size_t allocLength = set.capacity();

    set[1000000000] = Trit::Unknown;
    EXPECT_EQ(allocLength,set.capacity());
}

TEST(MemoryTests, ComparingOutOfBound) {

    TritSet set(1000);
    size_t allocLength = set.capacity();

    EXPECT_FALSE(Trit::True == set[2000000000]);
    EXPECT_EQ(allocLength,set.capacity());
}

TEST(MemoryTests, OutOfBoundAllocation){

    TritSet set(1000);
    size_t allocLength = set.capacity();

    set[1000000000] = Trit::True;
    EXPECT_LT(allocLength,set.capacity());

    allocLength = set.capacity();
    set[1000000000] = Trit::Unknown;
    set[1000000] = Trit::False;
    EXPECT_EQ(allocLength, set.capacity());
}

TEST(MemoryTests, ShrinkMemoryFree) {

    TritSet set(1000);
    size_t allocLength = set.capacity();

    set[1000000000] = Trit::True;

    allocLength = set.capacity();
    set[1000000000] = Trit::Unknown;
    set[1000000] = Trit::False;

    set.shrink();
    EXPECT_GT(allocLength,set.capacity());

}

TEST(MemoryTests, TritOperationAllocation) {

    TritSet setA(1000);
    TritSet setB(2000);

    TritSet setC = setA | setB;

    EXPECT_EQ(setA.capacity(), setB.capacity());
    EXPECT_EQ(setA.capacity(), setC.capacity());
}

TEST(TritOperationTests, OrTest) {

    TritSet setTruth(3);

    setTruth[0] = Trit::True;
    setTruth[1] = Trit::Unknown;
    setTruth[2] = Trit::Unknown;

    TritSet setA(3);
    TritSet setB(3);

    setA[0] = Trit::Unknown;
    setA[1] = Trit::Unknown;
    setA[2] = Trit::Unknown;

    setB[0] = Trit::True;
    setB[1] = Trit::False;
    setB[2] = Trit::Unknown;

    TritSet setC = setA | setB;

    for(int i=0; i<3; i++){
        EXPECT_TRUE(setC[i] == setTruth[i]);
    }
}

TEST(TritOperationTests, AndTest) {

    TritSet setTruth(3);

    setTruth[0] = Trit::Unknown;
    setTruth[1] = Trit::False;
    setTruth[2] = Trit::Unknown;

    TritSet setA(3);
    TritSet setB(3);

    setA[0] = Trit::Unknown;
    setA[1] = Trit::Unknown;
    setA[2] = Trit::Unknown;

    setB[0] = Trit::True;
    setB[1] = Trit::False;
    setB[2] = Trit::Unknown;

    TritSet setC = setA & setB;

    for(int i=0; i<3; i++){
        EXPECT_TRUE(setC[i] == setTruth[i]);
    }
}

TEST(TritOperationTests, NotTest) {

    TritSet setTruth(3);

    setTruth[0] = Trit::False;
    setTruth[1] = Trit::True;
    setTruth[2] = Trit::Unknown;

    TritSet setA(3);

    setA[0] = Trit::True;
    setA[1] = Trit::False;
    setA[2] = Trit::Unknown;

    TritSet setC = ~setA;

    for(int i=0; i<3; i++){
        EXPECT_TRUE(setC[i] == setTruth[i]);
    }
}

TEST(OtherFunctionsTests, CardinalityTest) {
    TritSet set(3);

    set[0] = Trit::True;
    set[1] = Trit::Unknown;
    set[2] = Trit::False;

    EXPECT_EQ(set.cardinality(Trit::False),1);
    EXPECT_EQ(set.cardinality(Trit::True),1);
    EXPECT_EQ(set.cardinality(Trit::Unknown),1);
}

TEST(OtherFunctionsTests, TrimTest) {
    TritSet set(4);

    set[0] = Trit::True;
    set[1] = Trit::Unknown;
    set[2] = Trit::False;
    set[3] = Trit::True;

    set.trim(2);
    EXPECT_TRUE(set[2]==Trit::Unknown && set[3]==Trit::Unknown);
}

TEST(OtherFunctionsTests, LenTest) {
    TritSet set(4);

    set[0] = Trit::True;
    set[1] = Trit::Unknown;
    set[2] = Trit::False;
    set[3] = Trit::Unknown;

    EXPECT_EQ(set.length(),3);
}

TEST(HashFunctionTests, TritHashTest) {
    TritSet::TritHash hash;
    EXPECT_FALSE(hash(Trit::True) != hash(Trit::False) && hash(Trit::False) != hash(Trit::Unknown) && hash(Trit::True) != hash(Trit::Unknown));
}