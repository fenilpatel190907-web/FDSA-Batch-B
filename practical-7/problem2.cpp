#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow" << endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    delete temp;
}

void display() {
    if (front == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}