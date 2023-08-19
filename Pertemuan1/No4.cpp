#include <iostream>
using namespace std;

#define ARR_SIZE 100

int maximum_of(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main() {
    int n; cin >> n;
    int arr[ARR_SIZE] = {0};

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool is_initialized = false;
    int max = 0, counter = 0;
    int current;
    for (int i = 0; i < n; i++) {
        if (!is_initialized) {
            is_initialized = true;
            current = arr[i];
            counter = 1;
            continue;
        }

        if (arr[i] != current) {
            max = maximum_of(max, counter);
            current = arr[i];
            counter = 1;
        } else {
            counter += 1;
        }
    }
    max = maximum_of(max, counter);

    cout << max << "\n";
    return 0;
}
