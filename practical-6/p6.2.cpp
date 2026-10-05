#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> pages;
    string page;
    int choice;

    while (cin >> choice) {
        if (choice == 1) {
            cin >> page;
            pages.push(page);
            cout << "Current Page: " << pages.top() << endl;
        }
        else if (choice == 2) {
            if (pages.size() <= 1) {
                cout << "No previous page" << endl;
            } else {
                pages.pop();
                cout << "Current Page: " << pages.top() << endl;
            }
        }
    }

    return 0;
}