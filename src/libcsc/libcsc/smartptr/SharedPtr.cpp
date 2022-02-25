#include "SharedPtr.h"

namespace my_smartptr {
    template<class T>
    SharedPtr<T>::SharedPtr():ptr_(nullptr), count_(0) {}

    template<class T>
    SharedPtr<T>::SharedPtr(T *ptr):ptr_(ptr), count_(1) {
    }

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