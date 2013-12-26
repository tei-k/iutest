
/*
 * is not available vprintf, can be replaced.
*/
//#define IUTEST_VPRINTF

/*
 * include testing framework
*/
#include <gmock/gmock.h>

#include "../../include/gtest/iutest_switch.hpp"


#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	::testing::InitGoogleMock(&argc, argv);
	IUTEST_INIT(&argc, argv);
	return IUTEST_RUN_ALL_TESTS();	// run all
}

/**
 * @brief	���b�N�Ώۂ̃I�u�W�F�N�g
*/
class Foo
{
public:
	virtual std::string name(void) = 0;
};

/**
 * @brief	���b�N
*/
class MockFoo : public Foo
{
public:
	MOCK_METHOD0( name, std::string () );
};

/**
 * @brief	�e�X�g�������N���X
*/
class FooTest
{
	Foo*	m_foo;
public:
	FooTest(Foo* foo) : m_foo(foo) {}

	std::string name(void) { return m_foo->name(); }
	std::string repeat(int n) 
	{
		std::string str;
		for( int i=0; i < n; ++i ) str += name();
		return str;
	}
};

TEST(FooTest, Name)
{
	// ���b�N
	MockFoo mock;
	EXPECT_CALL(mock, name()).WillOnce( ::testing::Return("iutest") );

	FooTest test(&mock);
	IUTEST_ASSERT_EQ( "iutest", test.name() );
}

using testing::Pointwise;
using testing::Lt;
using testing::Gt;
using testing::Not;

TEST(PointwiseTest, WorksForLhsNativeArray)
{
  const int lhs[] = { 1, 2, 3 };
  std::vector<int> rhs;
  rhs.push_back(2);
  rhs.push_back(4);
  rhs.push_back(6);
  EXPECT_THAT(lhs, Pointwise(Lt(), rhs));
  EXPECT_THAT(lhs, Not(Pointwise(Gt(), rhs)));
}