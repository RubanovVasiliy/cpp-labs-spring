#pragma once

#include <iostream>

namespace my_smartptr {

    template<typename T>
    class SharedPtr {
    private:
        T *ptr_ = nullptr;
        std::size_t *count_ = new size_t(0);

    public:
        SharedPtr() = default;

        explicit SharedPtr(T *ptr) : ptr_(static_cast<T *>(ptr)) {
            if (ptr != nullptr) {
                count_ = new size_t(1);
            }
        }

        SharedPtr(const SharedPtr &object) : ptr_(object.ptr_), count_(object.count_) {
            if (object.ptr_ != nullptr) {
                count_ = object.count_;
                (*count_)++;
            }
        };

        SharedPtr(SharedPtr &&object) noexcept: ptr_(object.ptr_), count_(object.count_) {
            object.ptr_ = nullptr;
            object.count_ = new size_t(0);
        }

        SharedPtr &operator=(const SharedPtr &object) {
            if (this == &object) {
                return *this;
            }

            ptr_ = object.ptr_;
            count_ = object.count_ + 1;
            return *this;
        }

        SharedPtr &operator=(SharedPtr &&object) noexcept {
            if (&object == this) {
                return *this;
            }

            delete ptr_;
            delete count_;

            ptr_ = object.ptr_;
            count_ = object.count_;
            object.ptr_ = nullptr;
            object.count_ = size_t(0);

            return *this;
        }

        ~SharedPtr() {
            if (*count_ < 0) {
                delete count_;
                delete ptr_;
            }
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
            delete count_;
            delete ptr_;
            ptr_ = static_cast<T *>(ptr);
            count_ = new size_t(0);
        }

        std::size_t use_count() {
            return *count_;
        }
    };
}