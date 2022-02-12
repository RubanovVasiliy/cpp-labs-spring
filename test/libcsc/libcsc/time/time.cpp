#include <string>
#include <gtest/gtest.h>
#include <MyTime.h>
#include <TimeSpan.h>


TEST(MyTime, TimeSpanAddTimeSpan) {

    const auto first = my_time::TimeSpan(1);
    const auto second = my_time::TimeSpan(3);

    const auto value = (first + second).getSeconds();

    const auto expected_value = my_time::TimeSpan(4).getSeconds();

    const std::string error_message = "error";

    ASSERT_EQ(value, expected_value) << error_message;
}

TEST(MyTime, TimeSpanSubTimeSpan) {

    const auto first = my_time::TimeSpan(5);
    const auto second = my_time::TimeSpan(-8);

    const auto value = (first - second).getSeconds();

    const auto expected_value = my_time::TimeSpan(3).getSeconds();

    const std::string error_message = "error";

    ASSERT_EQ(value, expected_value) << error_message;
}

TEST(MyTime, TimeAddTimeSpan) {

    const auto first = my_time::Time();
    const auto second = my_time::TimeSpan(2);

    const auto value = (first + second).getTime();

    const auto expected_value = (first.getTime() + 2);

    const std::string error_message = "error";

    ASSERT_EQ(value, expected_value) << error_message;
}

TEST(MyTime, TimeSubTimeSpan) {

    const auto first = my_time::Time();
    const auto second = my_time::TimeSpan(2);

    const auto value = (first - second).getTime();

    const auto expected_value = (first.getTime() - 2);

    const std::string error_message = "error";

    ASSERT_EQ(value, expected_value) << error_message;
}

/*
TEST(MyTime, TimeSubTime) {

    const auto first = my_time::Time();
    const auto second = my_time::Time();

    const auto value = 1;

    const auto expected_value = my_time::TimeSpan(0);

    const std::string error_message = "error";

    ASSERT_EQ(value, expected_value) << error_message;
}*/
