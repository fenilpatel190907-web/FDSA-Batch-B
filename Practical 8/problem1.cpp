
#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    void inorder(Node* node) {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == NULL)
            return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == NULL)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void levelOrder(Node* node) {
        if (node == NULL)
            return;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
};

int main() {
    BinaryTree t;

    t.root = new Node('A');
    t.root->left = new Node('B');
    t.root->right = new Node('C');
    t.root->left->left = new Node('D');
    t.root->left->right = new Node('E');
    t.root->right->left = new Node('F');
    t.root->right->right = new Node('G');

    cout << "Inorder: ";
    t.inorder(t.root);

    cout << "\nPreorder: ";
    t.preorder(t.root);

    cout << "\nPostorder: ";
    t.postorder(t.root);

    cout << "\nLevel Order: ";
    t.levelOrder(t.root);

    return 0;
}
