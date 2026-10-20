
#include <iostream>
using namespace std;

class Stack {
    int arr[5];
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        top = -1;
    }

    void push(int tray) {
        if (top == capacity - 1) {
            cout << "Error: Stack is full" << endl;
            return;
        }

        arr[++top] = tray;
        display();
    }

    void pop() {
        if (top == -1) {
            cout << "Error: Stack is empty" << endl;
            return;
        }

        cout << "Taken tray: " << arr[top--] << endl;
        display();
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Top tray: " << arr[top] << endl;
        }
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}
