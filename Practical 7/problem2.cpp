
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string patient;
    Node* next;

    Node(string name) {
        patient = name;
        next = NULL;
    }
};

class PatientQueue {
    Node* front;
    Node* rear;

public:
    PatientQueue() {
        front = rear = NULL;
    }

    void arrive(string name) {
        Node* newNode = new Node(name);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        display();
    }

    void attend() {
        if (front == NULL) {
            cout << "Error: No patients waiting" << endl;
            return;
        }

        Node* temp = front;
        cout << "Attended patient: " << temp->patient << endl;

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
        display();
    }

    void display() {
        if (front == NULL) {
            cout << "No patients waiting" << endl;
        } else {
            cout << "Front patient: " << front->patient << endl;
        }
    }
};

int main() {
    PatientQueue q;

    q.arrive("Amit");
    q.arrive("Riya");
    q.arrive("Jay");
    q.attend();
    q.attend();
    q.attend();
    q.attend();

    return 0;
}
