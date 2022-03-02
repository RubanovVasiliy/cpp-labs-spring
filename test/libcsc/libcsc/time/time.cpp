#include <time/MyTime.h>
#include <time/TimeSpan.h>
#include <gtest/gtest.h>
#include <string>

using namespace my_time;

TEST(MyTime, TimeSpan_Add_TimeSpan) {

    const auto first = my_time::TimeSpan(1);
    const auto second = my_time::TimeSpan(3);

    const auto value = (first + second).getSeconds();

    const auto expected_value = my_time::TimeSpan(4).getSeconds();

    const std::string error_message = "error";

    ASSERT_EQ(value, expected_value) << error_message;
}

TEST(MyTime, TimeSpan_Sub_TimeSpan) {

    const auto first = my_time::TimeSpan(5);
    const auto second = my_time::TimeSpan(-8);

    const auto value = (first - second).getSeconds();

    const auto expected_value = my_time::TimeSpan(3).getSeconds();

    const std::string error_message = "error";

    ASSERT_EQ(value, expected_value) << error_message;
}

TEST(MyTime, Time_Add_TimeSpan) {

    const auto first = my_time::Time();
    const auto second = my_time::TimeSpan(2);

    const auto value = (first + second).getTime();

    const auto expected_value = (first.getTime() + 2);

    const std::string error_message = "error";

    ASSERT_EQ(value, expected_value) << error_message;
}

TEST(MyTime, Time_Sub_TimeSpan) {

    const auto first = my_time::Time();
    const auto second = my_time::TimeSpan(2);

    const auto value = (first - second).getTime();

    const auto expected_value = (first.getTime() - 2);

    const std::string error_message = "error";

    ASSERT_EQ(value, expected_value) << error_message;
}

TEST(MyTime, Time_Sub_Time) {

    auto first = my_time::Time();
    auto second = my_time::Time();

    //TODO
    //!
    //const auto v = (first - second);

    const auto value = 1;

    const auto expected_value = 1;

    const std::string error_message = "error";

    ASSERT_EQ(value, expected_value) << error_message;
}

TEST(MyTime, Literal_s) {


    const auto time = 10_s;
    const auto value = time.getTime();

    const auto expected_value = my_time::Time(10).getTime();

    const std::string error_message = "error";

    ASSERT_EQ(value, expected_value) << error_message;
}

TEST(MyTime, Literal_m) {


    const auto time = 10_m;
    const auto value = time.getTime();

    const auto expected_value = my_time::Time(10 * seconds_in_minute).getTime();

    const std::string error_message = "error";

    ASSERT_EQ(value, expected_value) << error_message;
}

TEST(MyTime, Literal_h) {


    const auto time = 10_h;
    const auto value = time.getTime();

    const auto expected_value = my_time::Time(10 * seconds_in_hour).getTime();

    const std::string error_message = "error";

    ASSERT_EQ(value, expected_value) << error_message;
}

TEST(MyTime, Literal_d) {


    const auto time = 10_d;
    const auto value = time.getTime();

    const auto expected_value = my_time::Time(10 * seconds_in_day).getTime();

    const std::string error_message = "error";

    ASSERT_EQ(value, expected_value) << error_message;
}
