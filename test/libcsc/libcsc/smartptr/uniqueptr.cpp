#include <smartptr/UniquePtr.h>
#include <gtest/gtest.h>
#include <string>

const int INIT_VALUE = 10;

TEST(UniquePtr, operator_assignment) {
    auto obj = my_smartptr::UniquePtr<int>(new int(INIT_VALUE));

    auto ptr = my_smartptr::UniquePtr<int>(std::move(obj));
    EXPECT_TRUE(obj.get() == nullptr);

    const auto *value = ptr.get();
    const auto expected_value = int(INIT_VALUE);
    ASSERT_EQ(*value, expected_value);
}

TEST(UniquePtr, operator_multiplication) {
    auto obj = my_smartptr::UniquePtr<int>(new int(INIT_VALUE));

    const auto value = *obj;
    const auto expected_value = INIT_VALUE;
    ASSERT_EQ(value, expected_value);
}

TEST(UniquePtr, reset) {
    auto obj = my_smartptr::UniquePtr<int>(new int(1));
    obj.reset(new int(2));

    const auto value = *obj;
    const auto expected_value = 2;
    ASSERT_EQ(value, expected_value);
}

TEST(UniquePtr, reset_nullptr) {
    auto obj = my_smartptr::UniquePtr<int>(new int(1));
    obj.reset();

    EXPECT_TRUE(obj.get() == nullptr);
}

TEST(UniquePtr, get) {
    auto obj = my_smartptr::UniquePtr<int>(new int(INIT_VALUE));

    const auto *value = obj.get();
    const auto expected_value = int(INIT_VALUE);
    ASSERT_EQ(*value, expected_value);
}