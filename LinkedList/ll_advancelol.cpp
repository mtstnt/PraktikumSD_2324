#include <string>
#include <iostream>

using namespace std;

struct Data {
    string nama;
    int umur;

    Data() = default;
    Data(const string& nama, int umur) : nama(nama), umur(umur) {}
    Data(const Data& other) {
        std::cout << "COPY!\n";
        nama = other.nama;
        umur = other.umur;
    }
    Data(const Data&& other) {
        std::cout << "MOVE!\n";
        nama = other.nama;
        umur = other.umur;
    }
};

struct Node {
    Node* next = nullptr;
    Data& data;

    Node(Data& data) : data(data) {}
};

class SinglyLinkedList {
private:
    Node *head = nullptr, *tail = nullptr;

public:
    SinglyLinkedList() = default;
    SinglyLinkedList(const SinglyLinkedList& other) = delete;
    void operator=(const SinglyLinkedList& other) = delete;

    void add(Data&& data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = head;
            return;
        }
        tail->next = newNode;
        tail = tail->next;
        newNode->next = nullptr;
    }

    void print() {
        Node* t = head;
        while (t != nullptr) {
            std::cout << "{ " << "Nama: " << t->data.nama << " Umur: " << t->data.umur << " }\n";
            t = t->next;
        }
    }
};

void foo(SinglyLinkedList& ll) {
    ll.add(std::move(Data { "matthew", 19 }));
    ll.add(std::move(Data {"matthew 2", 20 }));
    ll.add(std::move(Data {"matthew 3", 21 }));
    ll.print();
}

int main() {
    SinglyLinkedList ll;
    foo(ll);
}
