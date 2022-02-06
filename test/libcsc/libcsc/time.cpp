#include <string>
#include <gtest/gtest.h>
#include <MyTime.h>


TEST(my_time, test_time) {
    const auto *const value = "DELETE";

    const auto *const expected_value = "DELETE";

    const std::string error_message = "error";

    ASSERT_EQ(value, expected_value) << error_message;
}
