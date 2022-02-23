#include <SharedPtr.h>
#include <UniquePtr.h>
#include <gtest/gtest.h>
#include <string>

TEST(MySmartptr, first) {

    //const auto first = 1;
    //const auto second = 2;

    const auto value = 1;

    const auto expected_value = 1;

    const std::string error_message = "error";

    ASSERT_EQ(value, expected_value) << error_message;
}
