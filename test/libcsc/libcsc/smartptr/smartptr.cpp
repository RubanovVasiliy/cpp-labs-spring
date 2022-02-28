#include <smartptr/UniquePtr.h>
#include <gtest/gtest.h>
#include <string>

using namespace my_smartptr;

struct Foo {
private:
    int a_;
public:
    explicit Foo(int in) : a_(in) {}

    void print() const {
        std::cout << "a = " << a_ << '\n';
    }

    void setA(int a) {
        Foo::a_ = a;
    }
};

TEST(MySmartptr, UniquePtr_operator_multiplication) {
    auto obj = UniquePtr<int>(new int(1));

    const auto value = *obj;
    const auto expected_value = 1;
    ASSERT_EQ(value, expected_value);
}

TEST(MySmartptr, UniquePtr_reset) {
    auto obj = UniquePtr<int>(new int(1));
    obj.reset(new int (2));

    auto value = *obj;
    auto expected_value = 2;
    ASSERT_EQ(value, expected_value);
}
