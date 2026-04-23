#pragma once
#include <memory>
#include <stdexcept>
#include "Node.h"

template <typename T>
class SinglyLinkedList {
private:
    std::shared_ptr<Node<T>> head;
    int size;

public:
    SinglyLinkedList() : head(nullptr), size{0} {}

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void push_front(T value) {
        auto NewNode = std::make_shared<Node<T>>(value);
        NewNode->next = head;
        head = NewNode;
        size++;
    }

    void push_back(T value) {
        auto NewNode = std::make_share<Node<T>>(value);
        if (isEmpty()) {
            head = tail = NewNode;
        } else {
            tail->next = NewNode;
            NewNode->prev = tail;
            tail =NewNode;
        }
        size++;
    }

    void pop_front() {
        if (isEmpty())
            throw std:: out_of_range("List is empty");

        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        size--;
    }

    void pop_back() {
        if (isEmpty())
            throw std::out_of_range("List is empty");

        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;

        size--;
    }

    T at(int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Invalid index");

        auto temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;

        return temp->data;
    }
    
    void print() const {
        auto temp = head;
        while (temp) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }


};
