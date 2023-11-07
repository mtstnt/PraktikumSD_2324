#include <iostream>

using namespace std;

/**
 * Tree: Acyclic Directed Graph
 * Menyimpan 2 - n child. Tergantung dengan kebutuhan.
*/

/**
 * Binary Tree -> sebuah tree yang mempunyai 2 child node, yaitu left dan right.
 * Seperti biasa, int bisa diubah menjadi tipe data lain.
*/
struct BinaryTreeNode {
    int value;
    BinaryTreeNode *left, *right;

    BinaryTreeNode(int value) : value(value), left(nullptr), right(nullptr) {}

    // Destructor kok boleh gini???
    // Karena dipanggil ketika kita panggil delete,
    //  nanti dia akan delete semua childnya secara rekursif.
    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

/**
 * Fungsi untuk buat node lebih singkat.
*/
BinaryTreeNode* createNode(int value) {
    return new BinaryTreeNode(value);
}

/**
 * Traversal dapat dilakukan dengan DFS, BFS seperti pada Graph.
 * Tapi ada beberapa istilah tambahan dari urutan print: preorder, inorder, postorder.
 * */
void preorder(BinaryTreeNode* node, int level = 1) {
    if (node == nullptr) return;

    cout << node->value << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(BinaryTreeNode* node) {
    if (node == nullptr) return;

    inorder(node->left);
    cout << node->value << " ";
    inorder(node->right);
}

void postorder(BinaryTreeNode* node) {
    if (node == nullptr) return;

    postorder(node->left);
    postorder(node->right);
    cout << node->value << " ";
}

int main(int argc, char** argv) {
    BinaryTreeNode* root = createNode(5);

    root->left = createNode(1);
    root->right = createNode(15);

    root->left->left = createNode(-3);
    root->left->right = createNode(8);

    root->right->left = createNode(12);

    cout << "do preorder\n";

    preorder(root);
    cout << "\n";

    inorder(root);
    cout << "\n";

    postorder(root);
    cout << "\n";

    cout << "done preorder\n";

    // Panggil destructor gini cukup.
    delete root;

    return 0;
}
