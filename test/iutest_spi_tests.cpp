//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_spi_tests.cpp
 * @brief		iutest_spi test
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2012, Takazumi Shirayanagi\n
 * The new BSD License is applied to this software.
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

//======================================================================
// include
#include "../include/gtest/iutest_spi_switch.hpp"

namespace spitest
{

const char* null_str = NULL;
int a=0, b=0;

IUTEST(SPITest, FatalFailure)
{
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_TRUE(false), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_FALSE(true), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_NULL((void*)1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_NOTNULL((void*)0), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_SAME(a, b), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_EQ(0, 1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_NE(1, 1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_LE(1, 0), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_LT(1, 0), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_GE(0, 1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_GT(0, 1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_FLOAT_EQ(0, 1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_DOUBLE_EQ(0, 1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_NEAR(0, 100, 2), "" );

	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STREQ("A", "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STREQ("A", null_str), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STREQ(null_str, "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRNE("a", "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRNE(null_str, null_str), "" );

	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ("b", "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ("b", null_str), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ(null_str, "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE("a", "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE("A", "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE(null_str, null_str), "" );

#if defined(IUTEST_OS_WINDOWS)
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_SUCCEEDED(-1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_FAILED(0), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_FAILED(100), "" );
#endif
}

IUTEST(SPITest, FatalFailure2)
{
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_TRUE(false), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_FALSE(true), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_NULL((void*)1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_NOTNULL((void*)0), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_SAME(a, b), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_EQ(0, 1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_NE(1, 1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_LE(1, 0), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_LT(1, 0), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_GE(0, 1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_GT(0, 1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_FLOAT_EQ(0, 1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_DOUBLE_EQ(0, 1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_NEAR(0, 100, 2), "" );

	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STREQ("A", "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STREQ("A", null_str), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STREQ(null_str, "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRNE("a", "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRNE(null_str, null_str), "" );

	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ("b", "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ("b", null_str), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ(null_str, "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE("a", "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE("A", "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE(null_str, null_str), "" );

#if defined(IUTEST_OS_WINDOWS)
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_SUCCEEDED(-1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_FAILED(0), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_FAILED(100), "" );
#endif
}

IUTEST(SPITest, NonFatalFailure)
{
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_TRUE(false), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_FALSE(true), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_NULL((void*)1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_NOTNULL((void*)0), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_SAME(a, b), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ(0, 1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_NE(1, 1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_LE(1, 0), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_LT(1, 0), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_GE(0, 1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_GT(0, 1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_FLOAT_EQ(0, 1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_DOUBLE_EQ(0, 1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_NEAR(0, 100, 2), "" );

	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ("A", "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ("A", null_str), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ(null_str, "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRNE("a", "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRNE(null_str, null_str), "" );

	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ("b", "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ("b", null_str), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ(null_str, "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE("a", "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE("A", "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE(null_str, null_str), "" );

#if defined(IUTEST_OS_WINDOWS)
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_SUCCEEDED(-1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_FAILED(0), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_FAILED(100), "" );
#endif
}

IUTEST(SPITest, NonFatalFailure2)
{
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_TRUE(false), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_FALSE(true), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_NULL((void*)1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_NOTNULL((void*)0), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_SAME(a, b), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ(0, 1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_NE(1, 1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_LE(1, 0), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_LT(1, 0), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_GE(0, 1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_GT(0, 1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_FLOAT_EQ(0, 1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_DOUBLE_EQ(0, 1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_NEAR(0, 100, 2), "" );

	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ("A", "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ("A", null_str), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ(null_str, "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRNE("a", "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRNE(null_str, null_str), "" );

	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ("b", "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ("b", null_str), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ(null_str, "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE("a", "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE("A", "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE(null_str, null_str), "" );

#if defined(IUTEST_OS_WINDOWS)
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_SUCCEEDED(-1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_FAILED(0), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_FAILED(100), "" );
#endif
}

#if IUTEST_HAS_VARIADIC_TEMPLATES

bool pred_test(int a0, int a1, int a2, int a3, int a4, int a5)
{
	return a0+a2+a4 == a1+a3+a5;
}

IUTEST(SPITest, VariadicPredTest)
{
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_PRED(pred_test, 1, 0, a, a, a, 0), "");
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_PRED(pred_test, 1, 0, a, a, a, 0), "");

	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_PRED(pred_test, 1, 0, a, a, a, 0), "");
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_PRED(pred_test, 1, 0, a, a, a, 0), "");
}

#endif

}

