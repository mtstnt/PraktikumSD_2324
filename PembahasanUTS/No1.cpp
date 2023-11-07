#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }
    Node* getHead()
    {
        return head;
    }
    bool isEmpty() {
        if (head == nullptr) {
            return true;
        }
        return false;
    }

    void insert(int data) {
        Node* temp = new Node;
        temp->data = data;        
        temp->next = nullptr;
        if (isEmpty()) {
            head = temp;
            head->next = nullptr;            
        }
        else {
            Node* temp2 = new Node;
            temp2 = head;
            while (temp2->next != nullptr) {
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }
    }

    void print() {
        Node* temp = head;
        if (!isEmpty()) {
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }    
};

int OutputKurang(Node* current)
{
    // Base case: 
    if (current->next == nullptr) {
        cout << current->data;
        return current->data;
    }
    // Recursive case:
    int kur = OutputKurang(current->next) - current->data;
    cout << " - " << current->data;
    return kur;
}

int OutputJumlah(Node* current)
{
    // Base case: 
    if (current->next == nullptr) {
        cout << current->data;
        return current->data;
    }
    // Recursive case:
    int jumlah = OutputJumlah(current->next) + current->data;
    cout << " + " << current->data;
    return jumlah;
}
// 1 3 4 7
// OutputJumlah(Node(3)) + 1
// OutputJumlah(Node(4)) + 3 + 1
// OutputJumlah(Node(7)) + 4 + 3 + 1
// 7 + 4 + 3 + 1
// 15

int main()
{
    LinkedList SLL;
    SLL.insert(1);
    SLL.insert(3);
    SLL.insert(4);
    SLL.insert(7);
    
    cout << "Output Jumlah: ";
    int totalJumlah = OutputJumlah(SLL.getHead());
    cout << " = " << totalJumlah << "\n";
    
    // OutputKurang(SLL.getHead());
    cout << "Output Kurang: ";
    int totalK= OutputKurang(SLL.getHead());
    cout << " = " << totalK << "\n";
    
    // LinkedList SLL2;
    // SLL2.insert(1);
    // SLL2.insert(4);
    // SLL2.insert(5);
    // SLL2.insert(8);
    
    // OutputJumlah(SLL2.getHead());
    // OutputKurang(SLL2.getHead());
    
    return 0;
}
