#pragma once

#include <iostream>

template<typename T>
class Stack {
private:
    struct Node {
        T value;
        Node* next;

        Node(T value) : value(value), next(nullptr) {}
    };
    Node* head;

public:
    Stack() : head(nullptr) {}

    void push(T value) {
        Node* n = new Node(value);
        if (head == nullptr) {
            head = n;
            return;
        }
        n->next = head;
        head = n;
    }

    T pop() {
        Node* current_head = head;
        if(head == nullptr) {
            std::cerr << "Stack is empty!\n";
            throw;
        }
        head = head->next;
        T value = current_head->value;
        delete current_head;
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
