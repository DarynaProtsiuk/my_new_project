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
        auto NewNode = std::make_shared<Node<T>>(value);
        if (isEmpty()) {
            head = NewNode;
        } else {
            auto temp = NewNode;
            while (temp->next)
                temp = temp->next;
            temp->next = NewNode;
        }

        size++;
    }

    void pop_front() {
        if (isEmpty())
            throw std:: out_of_range("List is empty");
        head = head->next;
        size--;
    }

    void pop_back() {
        if (isEmpty())
            throw std::out_of_range("List is empty");
        if (size == 1) {
            head = nullptr;
        } else {
            auto temp = head;
            while (temp->next->next)
                temp = temp->next;

            temp->next = nullptr;
        }

        size--;
    }

    void remove(int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Invalid index");

        if (index == 0) {
            pop_front();
            return;
        }

        auto temp = head;

        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        temp->next = temp->next->next;

        size--;
    }

    void insert(int index, T value) {
        if (index < 0 || index > size)
            throw std::out_of_range("Invalid index");

        if (index == 0) {
            push_front(value);
            return;
        }

        auto newNode = std::make_shared<Node<T>>(value);
        auto temp = head;

        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;

        size++;
    }

    T at(int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Invalid index");

        auto temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;

        return temp->data;
    }

    int find(T value) {
        auto temp = head;
        int index = 0;

        while (temp) {
            if (temp->data == value)
                return index;

            temp = temp->next;
            index++;
        }

        return -1;
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
