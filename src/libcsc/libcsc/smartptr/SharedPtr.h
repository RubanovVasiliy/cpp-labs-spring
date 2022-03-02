#pragma once

#include <iostream>

namespace my_smartptr {

    template<typename T>
    class SharedPtr {
    private:
        T *ptr_;
        std::size_t count_{0};

    public:
        SharedPtr() = default;

        explicit SharedPtr(T *ptr) : ptr_(static_cast<T *>(ptr)) {
            if (ptr != nullptr) {
                count_ = 1;
            }
        }

        SharedPtr(const SharedPtr &object) : ptr_(object.ptr_), count_(object.count_) {
            if (object.ptr_ != nullptr) {
                count_ = object.count_ + 1;
            }
        };

        SharedPtr(SharedPtr &&object) = delete;

        SharedPtr &operator=(const SharedPtr &object) {
            if (this == &object) {
                count_++;
                return *this;
            }

            ptr_ = object.ptr_;
            count_ = object.count_;
            return *this;
        }

        SharedPtr &operator=(SharedPtr &&object) = delete;

        ~SharedPtr() {
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
            count_ = 0;
        }

        std::size_t use_count() {
            return count_;
        }
    };
}