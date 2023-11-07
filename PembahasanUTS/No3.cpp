#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int getSize() {
        if (!isEmpty()) {
            Node* temp;
            temp = top;

            int size = 0;
            while (temp != nullptr) {
                size += 1;
                temp = temp->next;
            }
            return size;
        }
        return 0;
    }

    void push(int data) {
        Node* temp = new Node;
        temp->data = data;

        if (isEmpty()) {
            top = temp;
            top->next = nullptr;
        }
        else {
            temp->next = top;
            top = temp;
        }
    }
    
    void sortpush(int data){
        Node* temp = new Node;
        temp->data = data;
        if (isEmpty()) {
            top = temp;
            top->next = nullptr;
        }
        else {
            Stack sampah;
            while (!isEmpty() && data < top->data){
                sampah.push(pop());
            }
            
            push(data);
            
            while (!sampah.isEmpty()){
                push(sampah.pop());
            }
        }
    }

    int pop() {
        if (!isEmpty()) {
            Node* temp = new Node;
            temp = top;
            int value = top->data;

            top = top->next;
            delete temp;
            return value;
        }
        return -1;
    }

    void printAll() {
        if (!isEmpty()) {
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << endl;
                temp = temp->next;
            }
            cout << endl;
            cout << "Size: " << getSize() << endl;
            cout<<endl;
        }
    }


};

int main() {
    Stack coba1;
    coba1.sortpush(50);
    coba1.sortpush(100);
    coba1.sortpush(150);
    coba1.sortpush(200);
    coba1.printAll();

    int temp = coba1.pop();
    coba1.printAll();
    
    // cout << temp << endl;
    coba1.pop();

    coba1.printAll();

    return 0;
}
