
#include <iostream>
#include <string>
using namespace std;

struct SNode {
    string name;
    SNode* next;

    SNode(string s) {
        name = s;
        next = nullptr;
    }
};

class SinglyCircular {
    SNode* tail;

public:
    SinglyCircular() {
        tail = nullptr;
    }

    void join(string name, int pos) {
        SNode* n = new SNode(name);

        if (tail == nullptr) {
            n->next = n;
            tail = n;
            return;
        }

        if (pos <= 1) {
            n->next = tail->next;
            tail->next = n;
            return;
        }

        SNode* p = tail->next;
        int i = 1;

        while (i < pos - 1 && p != tail) {
            p = p->next;
            i++;
        }

        n->next = p->next;
        p->next = n;

        if (p == tail)
            tail = n;
    }

    void leave(string name) {
        if (tail == nullptr)
            return;

        SNode* p = tail->next;
        SNode* prev = tail;

        do {
            if (p->name == name) {
                if (p == prev) {
                    tail = nullptr;
                } else {
                    prev->next = p->next;
                    if (p == tail)
                        tail = prev;
                }

                delete p;
                return;
            }

            prev = p;
            p = p->next;
        } while (p != tail->next);
    }

    void display() {
        if (tail == nullptr) {
            cout << "Empty circle\n";
            return;
        }

        SNode* p = tail->next;
        cout << "Singly circular: ";

        do {
            cout << p->name << " -> ";
            p = p->next;
        } while (p != tail->next);

        cout << "(back to first)\n";
    }
};

struct DNode {
    string name;
    DNode* next;
    DNode* prev;

    DNode(string s) {
        name = s;
        next = prev = nullptr;
    }
};

class DoublyCircular {
    DNode* head;

public:
    DoublyCircular() {
        head = nullptr;
    }

    void join(string name, int pos) {
        DNode* n = new DNode(name);

        if (head == nullptr) {
            head = n;
            n->next = n;
            n->prev = n;
            return;
        }

        DNode* p = head;

        if (pos <= 1) {
            DNode* last = head->prev;
            n->next = head;
            n->prev = last;
            last->next = n;
            head->prev = n;
            head = n;
            return;
        }

        int i = 1;
        while (i < pos - 1 && p->next != head) {
            p = p->next;
            i++;
        }

        n->next = p->next;
        n->prev = p;
        p->next->prev = n;
        p->next = n;
    }

    void leave(string name) {
        if (head == nullptr)
            return;

        DNode* p = head;

        do {
            if (p->name == name) {
                if (p->next == p) {
                    head = nullptr;
                } else {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;

                    if (p == head)
                        head = p->next;
                }

                delete p;
                return;
            }

            p = p->next;
        } while (p != head);
    }

    void display() {
        if (head == nullptr) {
            cout << "Empty circle\n";
            return;
        }

        DNode* p = head;
        cout << "Doubly circular: ";

        do {
            cout << p->name << " <-> ";
            p = p->next;
        } while (p != head);

        cout << "(back to first)\n";
    }
};

int main() {
    SinglyCircular s;
    DoublyCircular d;

    string names[] = {"Amit", "Riya", "Jay"};

    for (int i = 0; i < 3; i++) {
        s.join(names[i], i + 1);
        d.join(names[i], i + 1);
        s.display();
        d.display();
    }

    cout << "\nRiya leaves:\n";
    s.leave("Riya");
    d.leave("Riya");
    s.display();
    d.display();

    cout << "\nNeha joins at position 2:\n";
    s.join("Neha", 2);
    d.join("Neha", 2);
    s.display();
    d.display();

    cout << "\nAmit leaves:\n";
    s.leave("Amit");
    d.leave("Amit");
    s.display();
    d.display();

    return 0;
}
