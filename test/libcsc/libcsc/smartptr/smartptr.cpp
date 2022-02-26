#include <SharedPtr.h>
#include <UniquePtr.h>
#include <gtest/gtest.h>
#include <string>

using my_smartptr::SharedPtr;

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

TEST(MySmartptr, SharedPtr_) {

    my_smartptr::SharedPtr<int> ptr1;

    //ASSERT_EQ(0,ptr1.use_count());

    auto ptr = std::make_shared<Foo>(10);
    //auto exep_ptr = my_smartptr::SharedPtr<Foo>(new Foo(10));

    //exep_ptr->print();

    //exep_ptr->print();
    //(*exep_ptr).print();

    ptr->print();
    (*ptr).print();

    const auto value = 1;

    const auto expected_value = 1;

    ASSERT_EQ(value, expected_value);
}
