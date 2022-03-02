#include <smartptr/SharedPtr.h>
#include <gtest/gtest.h>
#include <string>

const int INIT_VALUE = 10;

TEST(SharedPtr, operator_multiplication) {
    auto obj = my_smartptr::SharedPtr<int>(new int(INIT_VALUE));

    const auto value = *obj;
    const auto expected_value = INIT_VALUE;
    ASSERT_EQ(value, expected_value);
}

TEST(SharedPtr, reset) {
    auto obj = my_smartptr::SharedPtr<int>(new int(INIT_VALUE));
    obj.reset(new int(2));

    const auto value = *obj;
    const auto expected_value = 2;
    ASSERT_EQ(value, expected_value);
}

TEST(SharedPtr, reset_nullptr) {
    auto obj = my_smartptr::SharedPtr<int>(new int(INIT_VALUE));
    obj.reset();

    EXPECT_TRUE(obj.get() == nullptr);
}

TEST(SharedPtr, get) {
    auto obj = my_smartptr::SharedPtr<int>(new int(INIT_VALUE));

    const auto *value = obj.get();
    const auto expected_value = INIT_VALUE;
    ASSERT_EQ(*value, expected_value);
}

TEST(SharedPtr, use_count_0) {
    auto obj = my_smartptr::SharedPtr<int>(nullptr);

    const auto value = obj.use_count();
    const auto expected_value = 0;
    ASSERT_EQ(value, expected_value);
}

TEST(SharedPtr, use_count_1) {
    auto obj = my_smartptr::SharedPtr<int>(new int(INIT_VALUE));

    const auto value = obj.use_count();
    const auto expected_value = 1;
    ASSERT_EQ(value, expected_value);
}

TEST(SharedPtr, use_count_2) {
    auto obj = my_smartptr::SharedPtr<int>(new int(INIT_VALUE));
    auto ptr = my_smartptr::SharedPtr<int>(obj);

    const auto value = ptr.use_count();
    const auto expected_value = 2;
    ASSERT_EQ(value, expected_value);
}