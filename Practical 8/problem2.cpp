
#include <iostream>
using namespace std;

class Node {
public:
    int code;
    Node* left;
    Node* right;

    Node(int value) {
        code = value;
        left = right = NULL;
    }
};

class BST {
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == NULL)
            return new Node(value);

        if (value < node->code)
            node->left = insert(node->left, value);
        else if (value > node->code)
            node->right = insert(node->right, value);

        return node;
    }

    void inorder(Node* node) {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->code << " ";
        inorder(node->right);
    }

public:
    BST() {
        root = NULL;
    }

    void addBook(int value) {
        root = insert(root, value);
    }

    void display() {
        cout << "Inorder sequence: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int codes[] = {50, 30, 70, 20, 40, 60, 80};

    for (int code : codes)
        tree.addBook(code);

    tree.display();

    return 0;
}
