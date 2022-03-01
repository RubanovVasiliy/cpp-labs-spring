#include <smartptr/UniquePtr.h>
#include <gtest/gtest.h>
#include <string>

using namespace my_smartptr;

class Foo {
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

    bool operator==(Foo obj1) const {
        return this->a_ == obj1.a_;
    }
};

const int INIT_VALUE = 10;

TEST(UniquePtr, operator_multiplication) {
    auto obj = UniquePtr<int>(new int(INIT_VALUE));

    const auto value = *obj;
    const auto expected_value = INIT_VALUE;
    ASSERT_EQ(value, expected_value);
}

TEST(UniquePtr, reset) {
    auto obj = UniquePtr<int>(new int(1));
    obj.reset(new int(2));

    const auto value = *obj;
    const auto expected_value = 2;
    ASSERT_EQ(value, expected_value);
}

TEST(UniquePtr, get) {
    auto obj = std::make_unique<Foo>(Foo(INIT_VALUE));

    auto *value = obj.get();
    auto *expected_value = obj.get();
    ASSERT_EQ(value, expected_value);
}