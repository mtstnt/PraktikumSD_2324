#include <iostream>

using namespace std;

// Tree dapat didefinisikan dalam bentuk array.
// Dengan rumus tertentu, kita bisa mendapatkan semua data tanpa melakukan alokasi dinamis.

#define MAX_SIZE 100
#define EMPTY_VALUE INT_MIN

#define LEFT 0
#define RIGHT 1

void fill(int* tree, int size, int value) {
    for (int i = 0; i < size; i++) {
        tree[i] = value;
    }
}

void preorder(int* tree, int index) {
    if (tree[index] == EMPTY_VALUE) return;
    cout << tree[index] << " ";
    preorder(tree, index * 2 + 1);
    preorder(tree, index * 2 + 2);
}

void inorder(int* tree, int index) {
    if (tree[index] == EMPTY_VALUE) return;
    inorder(tree, index * 2 + 1);
    cout << tree[index] << " ";
    inorder(tree, index * 2 + 2);
}

void postorder(int* tree, int index) {
    if (tree[index] == EMPTY_VALUE) return;
    postorder(tree, index * 2 + 1);
    postorder(tree, index * 2 + 2);
    cout << tree[index] << " ";
}

int main(int argc, char** argv) {
    int binaryTree[MAX_SIZE];

    fill(binaryTree, MAX_SIZE, EMPTY_VALUE);

    // Rumus: index * 2 + 1 -> left; index * 2 + 2 -> right;

    // Set root.
    binaryTree[0] = 5;

    // Set left and right of root.
    binaryTree[0 * 2 + 1] = 1;
    binaryTree[0 * 2 + 2] = 15;

    // Set left and right of the left of root.
    binaryTree[1 * 2 + 1] = -3;
    binaryTree[1 * 2 + 2] = 8;

    // Set left of the right of root.
    binaryTree[2 * 2 + 1] = 13;

    preorder(binaryTree, 0);
    cout << "\n";

    inorder(binaryTree, 0);
    cout << "\n";

    postorder(binaryTree, 0);
    cout << "\n";

    return 0;
}
