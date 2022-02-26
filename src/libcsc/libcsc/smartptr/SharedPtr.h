#pragma once

#include <iostream>

namespace my_smartptr {

    template<typename T>
    class SharedPtr {
    private:
        T *ptr_;
        std::size_t count_{0};

    public:
        SharedPtr();

        explicit SharedPtr(T *ptr);

        SharedPtr(const SharedPtr &object);

        SharedPtr(SharedPtr &&object);

        //~SharedPtr() = default;

        T &operator*();

        T *operator->();

        T *get();

        void reset(T *p = nullptr);

        std::size_t use_count();
    };
}