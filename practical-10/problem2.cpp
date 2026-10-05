#include <iostream>
using namespace std;

#define SIZE 10

struct Node {
    int data;
    Node* next;
};

Node* hashTable[SIZE];

void insert(int key) {
    int index = key % SIZE;
    Node* newNode = new Node();
    newNode->data = key;
    newNode->next = NULL;
    
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << " --> ";
        Node* temp = hashTable[i];
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
    
    insert(15);
    insert(25);
    insert(35);
    insert(26);
    
    display();
    return 0;
}