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

    template<class T>
    SharedPtr<T>::SharedPtr():ptr_(nullptr) {}

    template<class T>
    SharedPtr<T>::SharedPtr(T *ptr):ptr_(&ptr), count_(1) {}

    template<class T>
    SharedPtr<T>::SharedPtr(const SharedPtr &object) : ptr_(new T), count_(object.count_) {
        *ptr_ = *object.m_ptr;
        ++count_;
    }

    template<class T>
    SharedPtr<T>::SharedPtr(SharedPtr &&object): ptr_(object.ptr_), count_(object.count_) {
        object.ptr_ = nullptr;
    }

    template<class T>
    T &SharedPtr<T>::operator*() {
        return *ptr_;
    }

    template<class T>
    T *SharedPtr<T>::operator->() {
        return ptr_;
    }

    template<class T>
    T *SharedPtr<T>::get() {
        return ptr_;
    }

    template<class T>
    void SharedPtr<T>::reset(T *p) {
        *ptr_ = std::move(p);
    }

    template<class T>
    std::size_t SharedPtr<T>::use_count() {
        return count_;
    }
}