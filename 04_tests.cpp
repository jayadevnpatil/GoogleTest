#include "pch.h"

// Source : https://google.github.io/googletest/primer.html

// ===========================================
// |                                         |
// |       VALUE PARAMETERIZED TESTS         |
// |                                         |
// ===========================================

// Value parameterized tests allow us to write a single test that can 
// be executed with multiple sets of input values.

// It is useful when intended to test the same logic or functionality 
// with various input values to ensure that it behaves correctly under 
// different conditions.

// =====================
//     How to Write 
// =====================

// * Define a test fixture cass by inheriting from testing::Test, write
// the SetUp() and TearDown() functions. Later define a new class which
// inherits from both fixture class and testing::WithParamInterface<T>

class BaseTest : public testing::Test 
{
    
};

template <typename T>
class BarTest : public BaseTest, public testing::WithParamInterface<T> 
{

};

// OR

// * Define define a class that inherits from testing::TestWithParam<T>
// directly
class FooTest : public testing::TestWithParam<bool> 
{

};

// Use the TEST_P macro to define it as a parameterized test

// GetParam() method is used to access the test parameters of the 
// TestWithParam<T> class
TEST_P(FooTest, DoesBlah) 
{
    EXPECT_TRUE(GetParam());
}

// Use the INSTANTIATE_TEST_SUITE_P/INSTANTIATE_TEST_CASE_P macro to 
// instantiate the test suite with any set of parameters

INSTANTIATE_TEST_CASE_P(
    ValParamTest, 
    FooTest, 
    testing::Values(true, false, true));

// ================================
//          Example Code 
// ================================

int addOne(int x)
{
	return x + 1;
}

class AdditionTest : public testing::TestWithParam<int>
{

};

TEST_P(AdditionTest, SampleTest)
{
    EXPECT_EQ(GetParam() + 1, addOne(GetParam()));
}

INSTANTIATE_TEST_CASE_P(
    intGroup,
    AdditionTest, 
    testing::Range(0, 3)
);