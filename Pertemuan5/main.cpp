#include "Stack.h"
#include "Queue.h"

int main() {
    std::cout << "Stack\n";

    Stack<int> s;
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);

    s.print();

    std::cout << "Pop: ";
    std::cout << s.pop() << "\n";

    s.print();

    std::cout << "\n";
    std::cout << "Queue\n";

    Queue<int> q;
    q.add(10);
    q.add(11);
    q.add(12);
    q.add(13);

    q.print();

    int first   = q.pop();
    std::cout << "1: " << first << "\n";
    int second  = q.pop();
    std::cout << "2: " << second << "\n";
    int third   = q.pop();
    std::cout << "3: " << third << "\n";

    q.print();

    return 0;
}
