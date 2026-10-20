
#include <iostream>
using namespace std;

class Queue {
    int arr[5];
    int front, rear, count, capacity;

public:
    Queue(int size) {
        front = 0;
        rear = -1;
        count = 0;
        capacity = size;
    }

    void join(int token) {
        if (count == capacity) {
            cout << "Error: Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = token;
        count++;
        display();
    }

    void serve() {
        if (count == 0) {
            cout << "Error: Queue is empty" << endl;
            return;
        }

        cout << "Served token: " << arr[front] << endl;
        front = (front + 1) % capacity;
        count--;
        display();
    }

    void display() {
        if (count == 0)
            cout << "Queue is empty" << endl;
        else
            cout << "Front token: " << arr[front] << endl;
    }
};

int main() {
    Queue q(5);

    q.join(101);
    q.join(102);
    q.join(103);
    q.serve();
    q.join(104);
    q.serve();
    q.serve();
    q.serve();
    q.serve();

    return 0;
}
