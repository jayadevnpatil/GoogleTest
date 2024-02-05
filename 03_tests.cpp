#include "pch.h"

// Source : https://google.github.io/googletest/primer.html

// ===========================================
// |                                         |
// |             TEST FIXTURES               |
// |                                         |
// ===========================================

// Whenever multiple tests use the same data or predetermined
// environment, instead of writing same set of instructions
// everytime we can use test fixtures

// Code Reusability : With fixtures, one can encapsulate common 
// setup and teardown code in a class.

// Improved Readability: By separating the common setup and 
// teardown code from the actual test logic, the test code 
// becomes more readable and focused on the specific functiona-
// -lity being tested.

// Isolation of Tests: Each test should ideally be independent 
// of others. Test fixtures help achieve this by providing a 
// fresh environment for each test

// ============================================
//      Instructions to create a fixture
// ============================================

// 1. Derive a class from testing::Test
// 2. Inside the class, declare any objects you plan to use
// 3. Use SetUpTestCase() function to run code before test suite 
//    starts
// 4. Use TearDownTestCase() function to run code after test suite
//    has finished
// 5. Constructor / SetUp() function to prepare the objects for
//    each test
// 6. Destructor / TearDown() function to release any resources
//    you allocated in SetUp() for each test


// Should I use the constructor / destructor of the test 
// fixture or SetUp() / TearDown() ?
// Refer Source : Testing FAQ


// ================================
//          Example Code 
// ================================

class MyTestFixture : public ::testing::Test {
protected:

    static void SetUpTestCase()
    {
        // Code to run once before the test suite starts
        std::cout << "Beginning of test suite" << std::endl;
    }

    static void TearDownTestCase()
    {
        // Code to run once after all tests in the suite are executed
        std::cout << "End of test suite" << std::endl;
    }

    void SetUp() override 
    {
        // Code to run before each test
        std::cout << "Beginning of test case" << std::endl;
    }

    void TearDown() override 
    {
        // Code to run after each test
        std::cout << "End of test case" << std::endl;
    }
};

TEST_F(MyTestFixture, Test1) {
    // Test logic specific to Test1
	std::cout << "TestCase 1" << std::endl;
    EXPECT_TRUE(true);
}

TEST_F(MyTestFixture, Test2) {
    // Test logic specific to Test2
    std::cout << "TestCase 2" << std::endl;
	EXPECT_TRUE(true);
}

// ================================
//          Sample Output
// ================================

//    [----------] 2 tests from MyTestFixture
//    Beginning of test suite
//    [RUN] MyTestFixture.Test1
//    Beginning of test case
//    TestCase 1
//    End of test case
//    [OK] MyTestFixture.Test1(1 ms)
//    [RUN] MyTestFixture.Test2
//    Beginning of test case
//    TestCase 2
//    End of test case
//    [OK] MyTestFixture.Test2(1 ms)
//    End of test suite
//    [----------] 2 tests from MyTestFixture(4 ms total)