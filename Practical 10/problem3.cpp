
#include <iostream>
using namespace std;

int main() {
    int table[10];

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    int n, id;
    cout << "Enter number of student IDs: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter student ID: ";
        cin >> id;

        int h1 = id % 10;
        int h2 = 7 - (id % 7);
        bool inserted = false;

        for (int j = 0; j < 10; j++) {
            int index = (h1 + j * h2) % 10;

            if (table[index] == -1) {
                table[index] = id;
                inserted = true;
                break;
            }
        }

        if (!inserted)
            cout << "Hash table is full; ID not inserted." << endl;
    }

    cout << "\nHash Table:\n";

    for (int i = 0; i < 10; i++) {
        cout << i << ": ";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }

    return 0;
}
