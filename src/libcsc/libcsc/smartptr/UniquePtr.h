#pragma once

#include <iostream>

namespace my_smartptr {

    template<class T>
    class UniquePtr {
    private:
        T *ptr_;

    public:
        UniquePtr() : ptr_(nullptr) {}

        explicit UniquePtr(T *ptr) : ptr_(static_cast<T *>(ptr)) {}

        UniquePtr(const UniquePtr &object) = delete;

        UniquePtr(UniquePtr &&object) noexcept: ptr_(object.ptr_) {
            object.ptr_ = nullptr;
        }

        UniquePtr &operator=(const UniquePtr &object) = delete;

        UniquePtr &operator=(UniquePtr &&object) noexcept {
            if (&object == this) {
                return *this;
            }

            delete ptr_;

            ptr_ = object.m_ptr;
            object.m_ptr = nullptr;

            return *this;
        }

        ~UniquePtr() {
            delete ptr_;
        };

        T &operator*() {
            return *ptr_;
        };

        T *operator->() {
            return ptr_;
        };

        T *get() {
            return ptr_;
        };

        void reset(T *const ptr = nullptr) {
            ptr_ = static_cast<T *>(ptr);
        }
    };
}