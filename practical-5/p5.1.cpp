#include <iostream>
using namespace std;

class Node {
public:
    string song;
    Node* next;
    Node* prev;

    Node(string s) {
        song = s;
        next = NULL;
        prev = NULL;
    }
};

class Playlist {
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
    }

    void addBeginning(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addEnd(string song) {
        Node* newNode = new Node(song);

        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAfter(string currentSong, string newSong) {
        Node* temp = head;

        while (temp != NULL && temp->song != currentSong) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Song not found" << endl;
            return;
        }

        Node* newNode = new Node(newSong);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }

        temp->next = newNode;
    }

    void removeFirst() {
        if (head == NULL) {
            cout << "Playlist is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }

        delete temp;
    }

    int countSongs() {
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->song << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Playlist p;

    p.addBeginning("Song1");
    p.display();

    p.addEnd("Song2");
    p.display();

    p.addEnd("Song3");
    p.display();

    p.insertAfter("Song2", "Song4");
    p.display();

    p.removeFirst();
    p.display();

    cout << "Total songs: " << p.countSongs() << endl;

    return 0;
}