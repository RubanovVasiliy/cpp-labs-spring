#pragma once

#include <iostream>

namespace my_smartptr {

    template <class T>
    class UniquePtr {
        T &operator*();
        T *operator->();
        T *get();
        void reset(T *p = nullptr);
    };
}