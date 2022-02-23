#include "SharedPtr.h"

namespace my_smartptr {
    template<class T>
    T &SharedPtr<T>::operator*() {
        return;
    }

    template<class T>
    T *SharedPtr<T>::operator->() {
        return nullptr;
    }

    template<class T>
    T *SharedPtr<T>::get() {
        return nullptr;
    }

    template<class T>
    void SharedPtr<T>::reset(T *p) {

    }

    template<class T>
    std::size_t SharedPtr<T>::use_count() {
        return 0;
    }
}