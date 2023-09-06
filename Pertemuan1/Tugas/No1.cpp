#include <iostream>
using namespace std;

bool is_prima(int n) {
    int counter = 0;
    for (int j = 1; j <= n; j++) {
        if (n % j == 0) {
            counter += 1;
        }
    }
    return counter == 2;
}

int main() {
    int n;
    cin >> n;

    int angka = 0;
    while (n > 0) {
        if (is_prima(angka)) {
            cout << angka << " ";
            n--;
        }
        angka += 1;
    }
    return 0;
}
