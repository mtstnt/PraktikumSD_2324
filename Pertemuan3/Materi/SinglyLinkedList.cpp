#include <iostream>

using namespace std;

struct Node{
    Node* next = nullptr;
    int value;

    Node(int value) : value(value) {}
};

class SinglyLinkedList {
private:
    Node *head, *tail;
public:
    SinglyLinkedList() : head(nullptr), tail(nullptr) {}

    ~SinglyLinkedList() {
        Node* n = head;
        while (n != nullptr) {
            Node* current = n;
            n = n->next;
            delete current;
        }
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = tail->next;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    int pop_back() {
        Node* to_delete = tail;
        int value = to_delete->value;

        Node* t = head;
        while (t->next != to_delete) {
            t = t->next;
        }
        t->next = nullptr;
        tail = t;
        delete to_delete;
        return value;
    }

    void print() {
        Node* t = head;
        while (t != nullptr) {
            cout << t->value << "\n";
            t = t->next;
        }
    }
};

int main() {
    SinglyLinkedList ll;
    ll.append(10);
    ll.append(11);
    ll.append(12);
    ll.append(13);
    ll.prepend(9);

    cout << "Semua:\n";
    ll.print();

    cout << "\n";
    int pop1 = ll.pop_back();
    cout << "Pop back: " << pop1 << "\n";
    ll.print();

    return 0;
}
