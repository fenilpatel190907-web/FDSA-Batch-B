#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

void insert(int key) {
    int index = key % SIZE;
    int i = 0;
    
    while (hashTable[(index + i) % SIZE] != -1 && i < SIZE) {
        i++;
    }
    
    if (i == SIZE) {
        cout << "Hash table is full" << endl;
    } else {
        hashTable[(index + i) % SIZE] = key;
    }
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1) {
            cout << i << " --> " << hashTable[i] << endl;
        } else {
            cout << i << " --> Empty" << endl;
        }
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
    
    insert(15);
    insert(25);
    insert(35);
    insert(26);
    
    display();
    return 0;
}