#pragma once


namespace my_list {

    template<typename T>
    class LinkedList {
    private:
        struct Node {
            T value;
            Node *next;
        };

        Node *head_;

    public:
        LinkedList() : head_(nullptr) {}

        LinkedList(const LinkedList &object) = delete;

        LinkedList(LinkedList &&object) = delete;

        ~LinkedList() {
            delete head_;
        };

        LinkedList &operator=(const LinkedList &object) = delete;

        LinkedList &operator=(LinkedList &&object) = delete;

        Node *getHead() const {
            return head_;
        }

        void setHead(Node *head) {
            head_ = head;
        }
    };

}