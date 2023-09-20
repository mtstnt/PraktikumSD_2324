#pragma once

#include <iostream>

template<typename T>
class Queue {
private:
    struct Node {
        T value;
        Node* next;

        Node(T value) : value(value), next(nullptr) {}
    };
    Node *head, *tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    void add(int value) {
        Node* n = new Node(value);
        if (head == nullptr) {
            head = n;
            tail = n;
            return;
        }
        tail->next = n;
        tail = n;
    }

    T pop() {
        if (head == nullptr) {
            throw;
        }
        Node* n = head;
        T value = n->value;
        head = head->next;
        delete n;
        return value;
    }

    void print() {
        Node* n = head;
        while (n != nullptr) {
            std::cout << n->value << "\n";
            n = n->next;
        }
    }
};
