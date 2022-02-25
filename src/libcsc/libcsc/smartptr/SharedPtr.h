#pragma once

#include <iostream>

namespace my_smartptr {

    template<class T>
    class SharedPtr {
    private:
        T *ptr_;
        std::size_t count_;

    public:
        SharedPtr();

        explicit SharedPtr(T *ptr);

        T &operator*();

        T *operator->();

        T *get();

        void reset(T *p = nullptr);

        std::size_t use_count();
    };
}