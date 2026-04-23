#ifndef MY_NEW_PROJECT_NODE_H
#define MY_NEW_PROJECT_NODE_H
#progma once
#include <memory>

template <typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> next;
    std::shared_ptr<Node<T>> prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

#endif //MY_NEW_PROJECT_NODE_H