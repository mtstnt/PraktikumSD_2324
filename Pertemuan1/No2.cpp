#include <iostream>
using namespace std;

#define ARR_SIZE 100

int main() {
    int arr1[ARR_SIZE], arr1_length;
    int arr2[ARR_SIZE], arr2_length;
    int arr3[ARR_SIZE];

    cin >> arr1_length;
    for (int i = 0; i < arr1_length; i++) {
        cin >> arr1[i];
    }

    cin >> arr2_length;
    for (int i = 0; i < arr2_length; i++) {
        cin >> arr2[i];
    }

    int p1 = 0, p2 = 0, p3 = 0;
    while (true) {
        if (p1 >= arr1_length && p2 >= arr2_length) break;

        if (p1 >= arr1_length) {
            arr3[p3] = arr2[p2];
            p3++; p2++;
            continue;
        }

        if (p2 >= arr2_length) {
            arr3[p3] = arr1[p1];
            p3++; p1++;
            continue;
        }

        if (arr1[p1] < arr2[p2]) {
            arr3[p3] = arr1[p1];
            p3++; p1++;
        } else {
            arr3[p3] = arr2[p2];
            p3++; p2++;
        }
    }

    for (int i = 0; i < p3; i++) {
        cout << arr3[i] << " ";
    }

    return 0;
}
