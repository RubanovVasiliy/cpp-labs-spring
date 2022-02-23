#pragma once

#include <iostream>

namespace my_smartptr {

    template <class T>
    class SharedPtr {
        T &operator*();
        T *operator->();
        T *get();
        void reset(T *p = nullptr);
        std::size_t use_count();
    };
}