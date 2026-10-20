
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = next = nullptr;
    }
};

class Playlist {
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = tail = nullptr;
    }

    void addBeginning(string s) {
        Node* n = new Node(s);

        if (head == nullptr) {
            head = tail = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
        display();
    }

    void addEnd(string s) {
        Node* n = new Node(s);

        if (tail == nullptr) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        display();
    }

    void insertAfter(string target, string s) {
        Node* p = head;

        while (p != nullptr && p->song != target)
            p = p->next;

        if (p == nullptr) {
            cout << "Song not found. ";
            display();
            return;
        }

        Node* n = new Node(s);
        n->prev = p;
        n->next = p->next;

        if (p->next != nullptr)
            p->next->prev = n;
        else
            tail = n;

        p->next = n;
        display();
    }

    void removeFirst() {
        if (head == nullptr) {
            cout << "Playlist is empty. ";
            display();
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;
        display();
    }

    int count() {
        int c = 0;
        Node* p = head;

        while (p != nullptr) {
            c++;
            p = p->next;
        }
        return c;
    }

    void display() {
        Node* p = head;
        cout << "Playlist: ";

        if (p == nullptr)
            cout << "Empty";

        while (p != nullptr) {
            cout << p->song;
            if (p->next != nullptr)
                cout << " <-> ";
            p = p->next;
        }

        cout << " | Count: " << count() << endl;
    }
};

int main() {
    Playlist p;

    p.addEnd("Song A");
    p.addEnd("Song B");
    p.addBeginning("Song C");
    p.insertAfter("Song A", "Song D");
    p.removeFirst();
    p.insertAfter("Song X", "Song E");

    return 0;
}
