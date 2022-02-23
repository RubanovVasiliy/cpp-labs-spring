#include "UniquePtr.h"

namespace my_smartptr {
    template<class T>
    T &UniquePtr<T>::operator*() {
        return;
    }

    template<class T>
    T *UniquePtr<T>::operator->() {
        return nullptr;
    }

    template<class T>
    T *UniquePtr<T>::get() {
        return nullptr;
    }

    template<class T>
    void UniquePtr<T>::reset(T *p) {

    }
}