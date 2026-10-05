#include <iostream>
using namespace std;

#define MAX 100
int arr[MAX];
int front = -1;
int rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow" << endl;
    } else {
        if (front == -1) front = 0;
        rear++;
        arr[rear] = val;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow" << endl;
    } else {
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty" << endl;
    } else {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
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