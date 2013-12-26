//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_util_quiet_result_printer.hpp
 * @brief		iris unit test quiet result printer �t�@�C��
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2012-2013, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IRIS_IUTEST_UTIL_QUIET_RESULT_PRINTER_HPP_0DF65DD7_C97C_44BA_940D_D22ED6AF9494_
#define INCG_IRIS_IUTEST_UTIL_QUIET_RESULT_PRINTER_HPP_0DF65DD7_C97C_44BA_940D_D22ED6AF9494_

//======================================================================
// include

namespace iuutil
{

//======================================================================
// class

/**
 * @brief	�R���p�N�g�ȃf�t�H���g�R���\�[���o�̓C�x���g���X�i�[
*/
class QuietResultPrinter : public ::iutest::TestEventListener
{
public:
	QuietResultPrinter(::iutest::TestEventListener* default_printer)
		: m_default_printer(default_printer)
	{}
	virtual ~QuietResultPrinter()
	{
		delete m_default_printer;
	}

public:
	virtual void OnTestProgramStart(const ::iutest::UnitTest& unit_test) { m_default_printer->OnTestProgramStart(unit_test); }

	virtual void OnTestIterationStart(const ::iutest::UnitTest& unit_test,
		int iteration) { m_default_printer->OnTestIterationStart(unit_test, iteration); }

	virtual void OnEnvironmentsSetUpStart(const ::iutest::UnitTest& unit_test) { m_default_printer->OnEnvironmentsSetUpStart(unit_test); }

	virtual void OnEnvironmentsSetUpEnd(const ::iutest::UnitTest& unit_test) { m_default_printer->OnEnvironmentsSetUpEnd(unit_test); }

	virtual void OnTestCaseStart(const ::iutest::TestCase& test_case) { m_default_printer->OnTestCaseStart(test_case); }

#if 0
	virtual void OnTestStart(const ::iutest::TestInfo& test_info) {}

	virtual void OnTestPartResult(const ::iutest::TestPartResult& test_part_result)
	{
		if( ::iutest::UnitTest::GetInstance()->current_test_info() != NULL )
		{
			const ::iutest::TestInfo& test_info = *::iutest::UnitTest::GetInstance()->current_test_info();
			if( test_info.result()->Failed()
				&& test_info.result()->total_part_count() == 1 )
			{
				m_default_printer->OnTestStart(test_info);
			}
		}
		m_default_printer->OnTestPartResult(test_part_result);
	}
#else
	virtual void OnTestStart(const ::iutest::TestInfo& test_info) { m_default_printer->OnTestStart(test_info); }

	virtual void OnTestPartResult(const ::iutest::TestPartResult& test_part_result) { m_default_printer->OnTestPartResult(test_part_result); }
#endif

	virtual void OnTestEnd(const ::iutest::TestInfo& test_info)
	{
		if( test_info.result()->Failed() )
		{
			// ���s�����Ƃ��̂ݏo�͂���
			m_default_printer->OnTestEnd(test_info);
		}
	}

	virtual void OnTestCaseEnd(const ::iutest::TestCase& test_case) { m_default_printer->OnTestCaseEnd(test_case); }

	virtual void OnEnvironmentsTearDownStart(const ::iutest::UnitTest& unit_test) { m_default_printer->OnEnvironmentsTearDownStart(unit_test); }

	virtual void OnEnvironmentsTearDownEnd(const ::iutest::UnitTest& unit_test) { m_default_printer->OnEnvironmentsTearDownEnd(unit_test); }

	virtual void OnTestIterationEnd(const ::iutest::UnitTest& unit_test,
		int iteration) { m_default_printer->OnTestIterationEnd(unit_test, iteration); }

	virtual void OnTestProgramEnd(const ::iutest::UnitTest& unit_test) { m_default_printer->OnTestProgramEnd(unit_test); }
private:
	::iutest::TestEventListener* m_default_printer;

public:
	/**
	 * @brief	QuietResultPrinter �ɐ؂�ւ�
	*/
	static void SetUp(void)
	{
		::iutest::TestEventListeners& listeners = ::iutest::UnitTest::GetInstance()->listeners();
		listeners.Append(new QuietResultPrinter(listeners.Release(listeners.default_result_printer())));
	}
};

}	// end of namespace iuutil

#endif	// INCG_IRIS_IUTEST_UTIL_QUIET_RESULT_PRINTER_HPP_0DF65DD7_C97C_44BA_940D_D22ED6AF9494_