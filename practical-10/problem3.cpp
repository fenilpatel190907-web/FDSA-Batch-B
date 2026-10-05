#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

int hash1(int key) {
    return key % SIZE;
}

int hash2(int key) {
    return 7 - (key % 7);
}

void insert(int key) {
    int index = hash1(key);
    int step = hash2(key);
    int i = 0;
    
    while (hashTable[(index + i * step) % SIZE] != -1 && i < SIZE) {
        i++;
    }
    
    if (i == SIZE) {
        cout << "Hash table is full" << endl;
    } else {
        hashTable[(index + i * step) % SIZE] = key;
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