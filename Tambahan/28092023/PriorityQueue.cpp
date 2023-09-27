#include <iostream>
#include <assert.h>

using namespace std;

/**
 * Priority Queue:
 * Queue yang mengutamakan antrian dengan prioritas yang lebih tinggi.
 * Dpt digunakan apabila mekanisme queue tetap diperlukan, tapi ada bbrp data yang diutamakan (bisa nyalip).
 *
 * Perhatikan bahwa implementasi SD apapun tidak harus ikutin yg kita ajari.
 * Selalu sesuaikan dengan kebutuhan sesuai soal.
 * Yang paling penting adalah konsep/cara kerjanya sama. Mis: Stack LIFO, Queue FIFO. Jgn dicampur-campur/tiba" bisa hapus node di tengah dll. Penyimpanan dgn array/linked list boleh.
 * Pastikan paham konsep + paham coding supaya bisa ez selesain soalnya.
 * Good luck buat UTSnya!
 *
 * Bingung? Chat di LINE atau tanya di GC. Cari aku di group LINE angkatan kalian.
 *
 * ~ Matthew
*/
template<typename T>
class PriorityQueue {
private:
    struct Node {
        Node* next;
        T value;
        int priority;

        // : property(value) -> Initializer List.
        Node(T value, int priority) :
            next(nullptr),
            value(value),
            priority(priority) {}
    };

    Node *head;

public:
    PriorityQueue() : head(nullptr) {}

    ~PriorityQueue() {
        Node *t = head, *prev = nullptr;
        while (t != nullptr) {
            prev = t;
            t = t->next;
            delete prev;
        }
    }

    void push(T value, int priority) {
        Node* n = new Node(value, priority);
        if (head == nullptr) {
            head = n;
            return;
        }

        // Kita masukkan menurut priority,
        //  semakin tinggi priority, masuknya semakin di depan (lbh cpt keluar)
        Node *t = head, *prev = nullptr;
        while (t != nullptr) {
            // Sampai ketemu priority yang lebih kecil dari priority nilai ini,
            //  masukkan di depannya.
            if (t->priority < priority) {
                if (prev == nullptr) {
                    // Kalau berhenti pas prev masih nullptr, berarti dia lbh tinggi prioritynya dari head.
                    n->next = head;
                    head = n;
                } else {
                    // Insert node baru ini di depannya `t`, karena priority node baru > priority node T.
                    prev->next = n;
                    n->next = t;
                }
                return;
            }
            prev = t;
            t = t->next;
        }
        // Kalau tidak masuk di bagian tengah, masuknya di paling belakang.
        prev->next = n;
    }

    T& front() const {
        assert(head != nullptr);
        return head->value;
    }

    T pop() {
        assert(head != nullptr);
        Node* t = head;
        T value = t->value;
        head = head->next;
        delete t;
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
    PriorityQueue<int> pq;
    pq.push(10, 5);
    pq.push(11, 5);
    pq.push(12, 8);
    pq.print();

    cout << "Pop 1 " << pq.pop() << "\n";
    cout << "Pop 2 " << pq.pop() << "\n";
    return 0;
}
