#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    int date;
    Node* next;
};

class Queue {
private:
    Node* front;
    int currentDate = 11;

public:
    int getCurrentDate(){
        return currentDate;
    }
    
    void plusDate(int besok){
        currentDate += besok;
    }
    
    Queue() {
        front = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enQueue(string nama, int date) {
        Node* temp = new Node;
        temp->nama = nama;
        temp->date = date;
        temp->next = nullptr;
        if (isEmpty()) {
            front = temp;
        }
        else {
            Node* currentNode = front;
            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }
            currentNode->next = temp;
        }
    }

    void deQueue() {
        while (!isEmpty() && front->date <= currentDate) {
            Node* hapus = front;
            string value = hapus->nama;
            front = front->next;

            delete hapus;
        }
    }

    void printAll() {
        Node* currentNode = front;
        while (currentNode != nullptr) {
            cout << currentNode->nama << " " << currentNode->date << endl;
            currentNode = currentNode->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    queue.enQueue("apel", 10);
    queue.enQueue("banana", 20);
    queue.enQueue("jeruk", 30);
    queue.enQueue("delima", 40);

    queue.printAll();
    cout<<endl;
    
    queue.plusDate(15);
    cout<<queue.getCurrentDate()<<endl;
    cout<<endl;
    
    queue.deQueue();
    queue.printAll();
    cout<<endl;

    return 0;
}
