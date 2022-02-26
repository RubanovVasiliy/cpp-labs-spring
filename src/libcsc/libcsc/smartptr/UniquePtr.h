#pragma once

#include <iostream>

namespace my_smartptr {

    template<class T>
    class UniquePtr {
    private:
        T *ptr;

    public:
        T &operator*();

        T *operator->();

        T *get();

        void reset(T *p = nullptr);
    };
}