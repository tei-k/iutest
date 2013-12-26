//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_spi_failure_tests.cpp
 * @brief		iutest spi failure test
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2013, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

//======================================================================
// include
#include "../include/iutest.hpp"
#include "../include/iutest_spi.hpp"

void FatalFailure1(void)
{
	IUTEST_FAIL();
}
void FatalFailure2(void)
{
	FatalFailure1();
	IUTEST_FAIL();
}

void NonFatalFailure1(void)
{
	IUTEST_ADD_FAILURE();
}
void NonFatalFailure2(void)
{
	NonFatalFailure1();
	IUTEST_ADD_FAILURE();
}

IUTEST(SPIAssertFailureTest, NoFailure)
{
	IUTEST_ASSERT_FATAL_FAILURE(return;, "");
}

IUTEST(SPIAssertFailureTest, Substr)
{
	IUTEST_ASSERT_FATAL_FAILURE(FatalFailure1();, "aaaa");
}

IUTEST(SPIAssertFailureTest, Different)
{
	IUTEST_ASSERT_FATAL_FAILURE(NonFatalFailure1();, "");
}

#if !IUTEST_USE_THROW_ON_ASSERT_FAILURE
IUTEST(SPIAssertFailureTest, Over)
{
	IUTEST_ASSERT_FATAL_FAILURE(FatalFailure2();, "");
}
#endif


IUTEST(SPIAssertNonFailureTest, NoFailure)
{
	IUTEST_ASSERT_NONFATAL_FAILURE(return;, "");
}

IUTEST(SPIAssertNonFailureTest, Substr)
{
	IUTEST_ASSERT_NONFATAL_FAILURE(NonFatalFailure1();, "aaaa");
}

IUTEST(SPIAssertNonFailureTest, Different)
{
	IUTEST_ASSERT_NONFATAL_FAILURE(FatalFailure1();, "");
}

IUTEST(SPIAssertNonFailureTest, Over)
{
	IUTEST_ASSERT_NONFATAL_FAILURE(NonFatalFailure2();, "");
}


IUTEST(SPIExpectFailureTest, NoFailure)
{
	IUTEST_EXPECT_FATAL_FAILURE(return;, "");
}

IUTEST(SPIExpectFailureTest, Substr)
{
	IUTEST_EXPECT_FATAL_FAILURE(FatalFailure1();, "aaaa");
}

IUTEST(SPIExpectFailureTest, Different)
{
	IUTEST_EXPECT_FATAL_FAILURE(NonFatalFailure1();, "");
}

#if !IUTEST_USE_THROW_ON_ASSERT_FAILURE
IUTEST(SPIExpectFailureTest, Over)
{
	IUTEST_EXPECT_FATAL_FAILURE(FatalFailure2();, "");
}
#endif

IUTEST(SPIExpectNonFailureTest, NoFailure)
{
	IUTEST_EXPECT_NONFATAL_FAILURE(return;, "");
}

IUTEST(SPIExpectNonFailureTest, Substr)
{
	IUTEST_EXPECT_NONFATAL_FAILURE(NonFatalFailure1();, "aaaa");
}

IUTEST(SPIExpectNonFailureTest, Different)
{
	IUTEST_EXPECT_NONFATAL_FAILURE(FatalFailure1();, "");
}

IUTEST(SPIExpectNonFailureTest, Over)
{
	IUTEST_EXPECT_NONFATAL_FAILURE(NonFatalFailure2();, "");
}


#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	IUTEST_INIT(&argc, argv);
#if defined(OUTPUTXML)
	// ���s�e�X�g���܂ނ̂� xml �o�͂��Ȃ�
	::iutest::IUTEST_FLAG(output) = NULL;
#endif
	const int ret = IUTEST_RUN_ALL_TESTS();
	if( ret == 0 ) return 1;
	
	IUTEST_ASSERT( ::iutest::UnitTest::GetInstance()->successful_test_count() == 0 );
	printf("*** Successful ***\n");
	return 0;
}