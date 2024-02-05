#include "pch.h"

// Source : https://google.github.io/googletest/primer.html

// ===========================================
// |                                         |
// |               ASSERTIONS                |
// |                                         |
// ===========================================

// Lists the assertion macros provided by GoogleTest for verifying code 
// behavior
// NOTE : The below list contains highly useful macros, refer official 
// site for more information

// ====================================
//     Explicit Success and Failure
// ====================================

// SUCCEED();
TEST(ExplicitSuccessFailure, SuccessTest)
{
	SUCCEED();
}

// FAIL()
TEST(ExplicitSuccessFailure, FailureTest)
{
	FAIL();
}

// ==============================
//       Boolean Condition
// ==============================

// EXPECT_TRUE(condition);
TEST(BooleanConditionSuite, TrueTest)
{
	bool condition = true;
	EXPECT_TRUE(condition);
}

// EXPECT_FALSE(condition);
TEST(BooleanConditionSuite, FalseTest)
{
	bool condition = false;
	EXPECT_FALSE(condition);
}

// ==============================
//	Binary Comparison
// ==============================

// EXPECT_EQ( val1, val2 )
TEST(BinaryComparisionSuite, EqualityTest)
{
	int x = 4;
	EXPECT_EQ(x, 4);
}

// EXPECT_NE( val1, val2 )
TEST(BinaryComparisionSuite, NonEqualityTest)
{
	int x = 4;
	EXPECT_NE(x, 2);
}

// EXPECT_LT( val1, val2 )	evaluates	val1 <  val2
// EXPECT_LE( val1, val2 )	evaluates	val1 <= val2
// EXPECT_GT( val1, val2 )	evaluates	val1 >  val2
// EXPECT_GE( val1, val2 )	evaluates	val1 >= val2

// ==============================
//	String Comparison
// ==============================

// String data type can be of 2 types : std::string and C-type strings
// below are the methods are used to compare strings for respective type

TEST(StringcomparisionSuite, StdStringEqualTest)
{
	std::string str1 = "Hello";
	std::string str2 = "Hello";
	EXPECT_EQ(str1, str2);
}

TEST(StringcomparisionSuite, StdStringNotEqualTest)
{
	std::string str1 = "Hello";
	std::string str2 = "HELLO";

	// Fails
	EXPECT_EQ(str1, str2);
}

// Verifies that the two C strings str1 and str2 have the same contents
// EXPECT_STREQ( str1, str2 )
TEST(StringcomparisionSuite, CStringEqualTest)
{
	const char word[6] = "Hello";
	EXPECT_STREQ(word, "Hello");
}

// Verifies that the two C strings str1 and str2 have different contents
// EXPECT_STRNE( str1, str2 )
TEST(StringcomparisionSuite, CStringNotEqualTest)
{
	const char word[6] = "Hello";
	EXPECT_STRNE(word, "HELLO");
}

// Verifies that the two C strings str1 and str2 have the same contents, 
// ignoring case
//EXPECT_STRCASEEQ( str1, str2 )

// Verifies that the two C strings str1 and str2 have different contents,
// ignoring case
// EXPECT_STRCASENE( str1, str2 )

// ===================================
//	Floating-Point Comparision
// ===================================

// Verifies that the two float values val1 and val2 are approximately equal, 
// to within 4 ULPs from each other.
// EXPECT_FLOAT_EQ( val1, val2 )

TEST(FloatComparisionSuite, FloatEqualTest)
{
	float f1 = 2.4563;
	float f2 = 2.4563;

	EXPECT_FLOAT_EQ(f1, f2);
}

// Verifies that the two double values val1 and val2 are approximately equal,
// to within 4 ULPs from each other
// EXPECT_DOUBLE_EQ( val1, val2 )

// Verifies that the difference between val1 and val2 does not exceed the 
// absolute error bound abs_error
// EXPECT_NEAR( val1, val2, abs_error)

// ===================================
//	Exception Assertion
// ===================================

// Pre-requisites
void ThrowErrorFunction()
{
	std::exception ex;
	throw ex;
}
void ThrowNoErrorFunction()
{

}

// Verifies that statement throws an exception of type exception_type.
// EXPECT_THROW( statement, exception_type )
TEST(ExceptionAssertionSuite, ExpectStdExceptionTest)
{
	EXPECT_THROW(ThrowErrorFunction(), std::exception);
}

// Verifies that statement throws an exception of any type.
// EXPECT_ANY_THROW( statement )
TEST(ExceptionAssertionSuite, ExpectAnyExceptionTest)
{
	EXPECT_ANY_THROW(ThrowErrorFunction());
}

// Verifies that statement does not throw any exception.
// EXPECT_NO_THROW( statement )
TEST(ExceptionAssertionSuite, ExpectNoExceptionTest)
{
	EXPECT_NO_THROW(ThrowNoErrorFunction());
}

// ===================================
//	  Predicate Assertions
// ===================================

// Verifies that the predicate pred returns true when passed 
// the given values as arguments.
// 
// pred : is a function or functor
// val1, val2, ... : input to the predicate
//
// EXPECT_PRED1(pred,val1 )
// EXPECT_PRED2(pred, val1, val2 )
// EXPECT_PRED3(pred, val1, val2, val3 )
// EXPECT_PRED4(pred, val1, val2, val3, val4 )
// EXPECT_PRED5(pred, val1, val2, val3, val4, val5 )

bool IsPositive(int n)
{
	bool result;
	return result = (n >= 0) ? true : false;
}

TEST(PredicateAssertionSuite, OneParamSuccessTest)
{
	EXPECT_PRED1(IsPositive, 2);
}

TEST(PredicateAssertionSuite, OneParamFailTest)
{
	EXPECT_PRED1(IsPositive, -4);
}

// ===================================
//	    Death Assertions
// ===================================

// Verifies that statement causes the process to terminate with a nonzero 
// exit status and produces stderr output that matches matcher.

// Reasons for death:
// 1. Program exited with nonzero exit status
// 2. Program was killed by a signal

// Convention: Test case name should end with "DeathTest"
// DeathTests usually need to be run before other tests

// EXPECT_DEATH( statement, matcher )
void DeathFunction()
{
	std::cerr << "My Error";
	exit(1);
}

TEST(TestSuite_DeathTest, sampleTest1)
{
	EXPECT_DEATH(DeathFunction(), "My Error");	
}

// If death tests are supported, behaves the same as EXPECT_DEATH. 
// Otherwise, verifies nothing
// EXPECT_DEATH_IF_SUPPORTED( statement, matcher )

// In debug mode, behaves the same as EXPECT_DEATH. When not in debug mode 
// (i.e. NDEBUG is defined), just executes statement.
// EXPECT_DEBUG_DEATH( statement, matcher )

// Verifies that statement causes the process to terminate with an exit status
// that satisfies predicate, and produces stderr output that matches matcher.
// EXPECT_EXIT( statement, predicate, matcher )

TEST(TestSuite_DeathTest, sampleTest2)
{
	EXPECT_EXIT(DeathFunction(), ::testing::ExitedWithCode(1), "");
}

// EXPECT_EXIT statement for normal exit condition

void NormalDeathFunction()
{
	std::cerr << "Success";
	exit(0);
}

TEST(TestSuite_DeathTest, sampleTest3)
{
	EXPECT_EXIT(NormalDeathFunction(), ::testing::ExitedWithCode(0), "Success");
}
