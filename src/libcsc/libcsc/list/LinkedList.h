#pragma once

#include <iostream>

namespace my_list {

    template<typename T>
    class LinkedList {
    private:
        struct Node {
            T value;
            Node *next;

            Node() = delete;

            explicit Node(const T &data = T(), Node *const next = nullptr)
                    : value(data), next(next) {}

            Node(const Node &other) = default;

            Node(Node &&node) = delete;

            ~Node() = default;

            Node operator=(const Node &node) = delete;

            Node operator=(Node &&node) = delete;
        };

        Node *head_;
        int size_;

    public:
        class Iterator {

            friend LinkedList;

        private:
            Node *ptr_;

        public:
            Iterator() : ptr_(nullptr) {}

            explicit Iterator(Node *ptr) : ptr_(ptr) {}

            Iterator(const Iterator &it) = default;

            ~Iterator() = default;

            bool operator==(const Iterator &it) { return ptr_ == it.ptr_; }

            bool operator!=(const Iterator &other) { return ptr_ != other.ptr_; }

            Iterator &operator++() {
                if (ptr_ != nullptr) {
                    ptr_ = ptr_->next;
                }
                return *this;
            }

            Iterator operator++(int) { return ++(*this); }

            Iterator operator+(int n) {
                for (int i = 0; i < n; i++) {
                    ++(*this);
                }
                return *this;
            }

            T &operator*() { return ptr_->value; }

            T *operator->() { return &ptr_->value; }
        };

        LinkedList() : head_(nullptr), size_(0) {}

        explicit LinkedList(T value) : size_(1) {
            head_ = new Node(value, head_);
        }

        LinkedList(const LinkedList &object) = delete;

        LinkedList(LinkedList &&object) = delete;

        ~LinkedList() { clear(); };

        LinkedList &operator=(const LinkedList &object) = delete;

        LinkedList &operator=(LinkedList &&object) = delete;

        void push_front(const T &value) {
            head_ = new Node(value, head_);
            size_++;
        }

        void push_back(const T &value) {
            if (head_ != nullptr) {
                Node *node = head_;
                while (node->next != nullptr) {
                    node = node->next;
                }
                node->next = new Node(value);
            } else {
                head_ = new Node(value, head_);
            }
            size_++;
        }

        void pop_front() {
            if (head_ != nullptr) {
                Node *node = head_;
                head_ = head_->next;
                delete node;
                size_--;
            }
        }

        void pop_back() {
            if (head_ != nullptr) {
                if (head_->next != nullptr) {
                    Node *node = head_;
                    head_ = nullptr;
                    delete node;
                } else {
                    Node *node = head_;
                    Node *prev = nullptr;
                    while (node->next != nullptr) {
                        prev = node;
                        node = node->next;
                    }
                    prev->next = nullptr;
                    delete node;
                }
                size_--;
            }
        }

        T &front() const {
            if (head_ != nullptr) {
                return head_->value;
            }
            throw std::exception();
        }

        T &back() const {
            Node *node = head_;
            while (node->next != nullptr) {
                node = node->next;
            }
            if (node != nullptr) {
                return node->value;
            }
            throw std::exception();
        }

        int size() { return size_; }

        void clear() {
            while (size_ > 0) {
                pop_front();
            }
        }

        void make_loop() {
            if (size_ == 1) {
                head_->next = head_;
            } else if (head_ != nullptr) {
                Node *node = head_;
                while (node->next != nullptr) {
                    node = node->next;
                }
                node->next = head_->next;
            } else {
                throw std::exception();
            }
        }

        bool isLooped() {
            if (head_ == nullptr) {
                return false;
            }

            Iterator hare(head_);
            Iterator turtle(head_);

            while (turtle.ptr_ != nullptr) {
                turtle = ++turtle;
                if (turtle.ptr_ != nullptr) {
                    hare = hare + 2;
                } else {
                    return false;
                }
                if (hare == turtle) {
                    return true;
                }
            }
            return false;
        }

        Iterator begin() {
            Iterator it(head_);
            return it;
        }

        Iterator end() {
            Iterator it(head_);
            while (it.ptr_ != nullptr) {
                it++;
            }
            return it;
        }
    };
}