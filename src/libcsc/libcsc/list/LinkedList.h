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
        private:
            friend LinkedList;

            Node *value_;

        public:
            bool operator!=(const Iterator &iterator) {
                return value_ != iterator.value_;
            }

            Iterator &operator++() {
                value_++;
                return *this;
            }

            Node &operator*() {
                return *value_;
            }
        };

        LinkedList() : head_(nullptr), size_(0) {}

        explicit LinkedList(T value) : size_(1) {
            head_ = new Node(value, head_);
        }

        LinkedList(const LinkedList &object) = delete;

        LinkedList(LinkedList &&object) = delete;

        ~LinkedList() {
            clear();
        };

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

        int size() {
            return size_;
        }

        void clear() {
            while (size_ > 0) {
                pop_front();
            }
        }

        Iterator begin() {
            Iterator it;
            it.value_ = head_;
            return it;
        }

        Iterator end() {
            Iterator it;
            it.value_ = head_;
            while (it.value_ != nullptr) {
                it.value_ = it.value_->next;
            }
            return it;
        }
    };
}