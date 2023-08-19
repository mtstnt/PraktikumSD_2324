#include <iostream>
#include <string>
using namespace std;

#define CHAR_COUNT 27

bool is_anagram(const string& a, const string& b) {
    int counts[CHAR_COUNT] = {0};
    for (int i = 0; i < a.length(); i++) {
        counts[tolower(a[i]) - 'a'] += 1;
    }
    for (int i = 0; i < b.length(); i++) {
        counts[tolower(b[i]) - 'a'] -= 1;
    }
    for (int i = 0; i < CHAR_COUNT; i++) {
        if (counts[i] > 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string a, b;
    cin >> a >> b;

    if (is_anagram(a, b)) {
        cout << "anagram\n";
    } else {
        cout << "bukan anagram\n";
    }

    return 0;
}
