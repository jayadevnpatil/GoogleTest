#include "pch.h"

// Source : https://google.github.io/googletest/primer.html

// ===========================================
// |                                         |
// |              INTRODUCTION               |
// |                                         |
// ===========================================
// 
// Assertions are the statements that check whether a condition is true. An
// assertion can result in success, fatal failure and non fatal failure depending
// on the condition 

// Tests : Use assertions to check a condition 
// Test Suite : A set of tests grouped together
// Test Program : Contains many test suites

// Types of assertions
//	- ASSERT_* : Generates fatal failures when condition fails, aborts the 
//		     current funtion
//	- EXPECT_* : Generates non-fatal failures when condition fails, does not
//		     aborts current funtion, continues to execute next statements

// NOTE : Streaming the macro ASSERT/EXPECT into `<<` operator produce custom 
//        failure messages

// Generation of sample test case
//	1. Use `TEST()` to define and name test function
//	2. Any valid C++ and GooglTest statments are valid inside this function
//	3. If any of the multiple assertions fails, entire test funtion fails

TEST(TestSuiteName, TestName) 
{
	// Test body 
	EXPECT_TRUE(true) << "Using EXPECT macro";
	ASSERT_TRUE(true) << "Using ASSERT macro";
} 
