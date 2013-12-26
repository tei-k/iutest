//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_value_tmp_tests.hpp
 * @brief		iris unit test template �l�������N���X�e�X�g �t�@�C��
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
#ifndef INCG_IRIS_IUTEST_VALUE_TMP_TESTS_HPP_8C9EC454_788D_4605_984B_0686C969E531_
#define INCG_IRIS_IUTEST_VALUE_TMP_TESTS_HPP_8C9EC454_788D_4605_984B_0686C969E531_

//======================================================================
// include
#include "../iutest_typed_tests.hpp"

#if IUTEST_HAS_TYPED_TEST

//======================================================================
// define
/**
 * @ingroup	TESTDEF
 * @def		IUTEST_VALUETMP_TEST_CASE(testcase_, types_)
 * @brief	�^�t���e�X�g�P�[�X�̓o�^
*/
#define IUTEST_VALUETMP_TEST_CASE(testcase_, types_)	IIUT_TYPED_TEST_CASE_(testcase_, types_)

/**
 * @ingroup	TESTDEF
 * @def		IUTEST_VALUETMP_TEST(testcase_, testname_)
 * @brief	�^�t���e�X�g�֐���`�}�N��
*/

#define IUTEST_VALUETMP_TEST(testcase_, testname_)		IIUT_VALUETMP_TEST_(testcase_, testname_)


/**
 * @private
 * @{
*/
#define IIUT_VALUETMP_TEST_(testcase_, testname_)										\
	template<iutest::BiggestInt iutest_ValueParam>										\
	class IUTEST_TEST_CLASS_NAME_(testcase_, testname_) : public testcase_<iutest_ValueParam> {		\
		typedef testcase_<iutest_ValueParam> TestFixture;								\
		static const iutest::BiggestInt ValueParam = iutest_ValueParam;					\
		protected: virtual void Body(void);												\
	};																					\
	iutest::tr1::ValueTmpParamTestInstance<IUTEST_TEST_CLASS_NAME_(testcase_, testname_), IUTEST_TYPED_TEST_PARAMS_(testcase_)>	\
	s_##testcase_##_##testname_( #testcase_, #testname_);								\
	template<iutest::BiggestInt iutest_ValueParam>										\
	void IUTEST_TEST_CLASS_NAME_(testcase_, testname_)<iutest_ValueParam>::Body(void)

/**
 * @}
*/

//======================================================================
// class
namespace iutest {
namespace tr1
{

template<typename T>
struct TypeAndValues
{
	template<T V>
	struct Value
	{
		static const T kValue = V;
	};
};

}	// end of namespace tr1

template<BiggestInt V>
struct TemplateValue : public tr1::TypeAndValues<BiggestInt>::Value<V> {};

namespace tr1
{

/**
 * @private
 * @internal
 * @brief	Type�p�����[�^�P�̃e�X�g�C���X�^���X
 * @tparam	Tester		= �e�X�g�N���X
 * @tparam	TypePrams	= �^
*/
template<template <BiggestInt V> class Tester, typename TypePrams>
class ValueTmpParamTestInstance
{
	/**
	 * @brief	�e�X�g�P�[�X���̍쐬
	 * @param [in]	testcase	= �x�[�X��
	 * @param [in]	index		= �^�C���f�b�N�X
	*/
	static ::std::string MakeTestCaseName(const char* testcase, int index)
	{
		::std::string name = testcase;
		detail::iuStringStream::type strm; strm << index;
		name += "/";
		name += strm.str();
		return name;
	}

	/**
	 * @brief	�e�e�X�g�̃C���X�^���X
	*/
	template<typename TT, typename DMY=void>
	class EachTest
	{
		typedef typename TT::Head			TypeParam;
		typedef Tester<TypeParam::kValue>	TestBody;
		typedef TypedTestCase<TypeParam>	_MyTestCase;
	public:
		// �R���X�g���N�^
		EachTest(const char* testcase, const char* name, int index)
			: m_mediator(UnitTest::instance().AddTestCase<_MyTestCase>(
				MakeTestCaseName(testcase, index).c_str()
				, internal::GetTypeId<detail::None>()	// TypeId �𓝈ꂷ�邽�߃_�~�[������n��
				, TestBody::SetUpTestCase
				, TestBody::TearDownTestCase))
			, m_info(&m_mediator, name, &m_factory)
			, m_next(testcase, name, index+1)
		{
		}
	public:
		// �e�X�g�̓o�^
		void	AddTest(void)
		{
			// ���Ԓʂ�ɂȂ�悤�ɑO����o�^
			UnitTest::instance().AddTestInfo(m_mediator.ptr(), &m_info);
			m_next.AddTest();
		}
	private:
		detail::TestCaseMediator	m_mediator;
		TestInfo					m_info;
		detail::iuFactory<TestBody>	m_factory;

		EachTest<typename TT::Tail>	m_next;
	};

	// �I�[
	template<typename DMY>
	class EachTest<detail::TypeList0, DMY>
	{
	public:
		EachTest(const char* /*testcase*/, const char* /*name*/, int /*index*/)	{}
		void	AddTest(void) {}
	};

public:
	// �R���X�g���N�^
	ValueTmpParamTestInstance(const char* testcase, const char* name)
		: m_tests(testcase, name, 0)
	{
		m_tests.AddTest();
	}

private:
	EachTest<TypePrams>	m_tests;
};

}	// end of namespace tr1
}	// end of namespace iutest

#endif

#endif