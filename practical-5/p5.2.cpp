#include <iostream>
using namespace std;

class SNode {
public:
    string name;
    SNode* next;

    SNode(string n) {
        name = n;
        next = NULL;
    }
};

class SinglyCircular {
    SNode* head;

public:
    SinglyCircular() {
        head = NULL;
    }

    void join(string name) {
        SNode* newNode = new SNode(name);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        SNode* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void leave(string name) {
        if (head == NULL)
            return;

        if (head->name == name) {
            if (head->next == head) {
                delete head;
                head = NULL;
                return;
            }

            SNode* temp = head;
            while (temp->next != head)
                temp = temp->next;

            SNode* del = head;
            head = head->next;
            temp->next = head;
            delete del;
            return;
        }

        SNode* temp = head;

        while (temp->next != head && temp->next->name != name)
            temp = temp->next;

        if (temp->next != head) {
            SNode* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "Empty" << endl;
            return;
        }

        SNode* temp = head;

        do {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

class DNode {
public:
    string name;
    DNode* next;
    DNode* prev;

    DNode(string n) {
        name = n;
        next = NULL;
        prev = NULL;
    }
};

class DoublyCircular {
    DNode* head;

public:
    DoublyCircular() {
        head = NULL;
    }

    void join(string name) {
        DNode* newNode = new DNode(name);

        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        DNode* tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }

    void leave(string name) {
        if (head == NULL)
            return;

        DNode* temp = head;

        do {
            if (temp->name == name) {
                if (temp->next == temp) {
                    delete temp;
                    head = NULL;
                    return;
                }

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head)
                    head = temp->next;

                delete temp;
                return;
            }

            temp = temp->next;
        } while (temp != head);
    }

    void display() {
        if (head == NULL) {
            cout << "Empty" << endl;
            return;
        }

        DNode* temp = head;

        do {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main() {
    SinglyCircular s;

    s.join("A");
    s.display();

    s.join("B");
    s.display();

    s.join("C");
    s.display();

    s.leave("B");
    s.display();

    DoublyCircular d;

    d.join("A");
    d.display();

    d.join("B");
    d.display();

    d.join("C");
    d.display();

    d.leave("B");
    d.display();

    return 0;
}