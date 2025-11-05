/**
 * Unit Tests for Password class
**/

#include <cassert>
#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, zero_letter_password)
{
    Password my_password;
    int actual = my_password.count_leading_characters("");
    ASSERT_EQ(0, actual);
}
TEST(PasswordTest, repeated_characters)
{
    Password my_password;
    int actual = my_password.count_leading_characters("aaa");
    ASSERT_EQ(3, actual);
}
TEST(PasswordTest, non_alphanum_characters)
{
    Password my_password;
    int actual = my_password.count_leading_characters("{{aaa");
    ASSERT_EQ(2, actual);
}
TEST(PasswordTest, empty_string_casechange)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("");
    ASSERT_EQ(false, actual);
}
TEST(PasswordTest, mixed_case)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("aA");
    ASSERT_EQ(true, actual);
}
TEST(PasswordTest, same_case)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("aa");
    ASSERT_EQ(true, actual);
}
