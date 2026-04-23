#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>
#include "Node.h"

template<typename T>
class DoublyLinkedList {
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void push_front(T value) {
        auto newNode = std::make_shared<Node<T>>(value);

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        size++;
    }

    void push_back(T value) {
        auto newNode = std::make_shared<Node<T>>(value);

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail; // OK (weak_ptr приймає shared_ptr)
            tail = newNode;
        }

        size++;
    }

    void pop_front() {
        if (isEmpty())
            throw std::out_of_range("List is empty");

        head = head->next;

        if (head)
            head->prev.reset(); // очищає weak_ptr
        else
            tail = nullptr;

        size--;
    }

    void pop_back() {
        if (isEmpty())
            throw std::out_of_range("List is empty");

        tail = tail->prev.lock();  // 🔥 важливо

        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;

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