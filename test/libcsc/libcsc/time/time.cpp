#include <time/MyTime.h>
#include <time/TimeSpan.h>
#include <gtest/gtest.h>
#include <string>

using namespace my_time;

TEST(MyTime, TimeSpan_Add_TimeSpan) {
    const auto first = TimeSpan(1);
    const auto second = TimeSpan(3);

    const auto value = (first + second).getSeconds();

    const auto expected_value = TimeSpan(4).getSeconds();
    ASSERT_EQ(value, expected_value);
}

TEST(MyTime, TimeSpan_Sub_TimeSpan) {
    const auto first = TimeSpan(5);
    const auto second = TimeSpan(-8);

    const auto value = (first - second).getSeconds();

    const auto expected_value = TimeSpan(3).getSeconds();
    ASSERT_EQ(value, expected_value);
}

TEST(MyTime, Time_Add_TimeSpan) {
    const auto first = Time();
    const auto second = TimeSpan(2);

    const auto value = (first + second).getTime();

    const auto expected_value = (first.getTime() + 2);
    ASSERT_EQ(value, expected_value);
}

TEST(MyTime, Time_Sub_TimeSpan) {
    const auto first = Time();
    const auto second = TimeSpan(2);

    const auto value = (first - second).getTime();

    const auto expected_value = (first.getTime() - 2);
    ASSERT_EQ(value, expected_value);
}

TEST(MyTime, Time_Sub_Time) {
    auto first = Time();
    sleep(1);
    auto second = Time();

    const auto value = (first - second).getSeconds();

    const auto expected_value = 1;
    ASSERT_EQ(value, expected_value);
}

TEST(MyTime, Literal_s) {
    const auto time = 10_s;
    const auto value = time.getTime();

    const auto expected_value = Time(10).getTime();
    ASSERT_EQ(value, expected_value);
}

TEST(MyTime, Literal_m) {
    const auto time = 10_m;
    const auto value = time.getTime();

    const auto expected_value = Time(10 * seconds_in_minute).getTime();
    ASSERT_EQ(value, expected_value);
}

TEST(MyTime, Literal_h) {
    const auto time = 10_h;
    const auto value = time.getTime();

    const auto expected_value = Time(10 * seconds_in_hour).getTime();
    ASSERT_EQ(value, expected_value);
}

TEST(MyTime, Literal_d) {
    const auto time = 10_d;
    const auto value = time.getTime();

    const auto expected_value = Time(10 * seconds_in_day).getTime();
    ASSERT_EQ(value, expected_value);
}
