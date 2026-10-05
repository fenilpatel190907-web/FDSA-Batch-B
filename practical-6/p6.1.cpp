#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int stack[100];
    int top = -1;
    int choice, value;

    while (cin >> choice) {
        if (choice == 1) {
            cin >> value;

            if (top == n - 1) {
                cout << "Stack Overflow" << endl;
            } else {
                stack[++top] = value;
                cout << "Top: " << stack[top] << endl;
            }
        }
        else if (choice == 2) {
            if (top == -1) {
                cout << "Stack Underflow" << endl;
            } else {
                top--;

                if (top == -1)
                    cout << "Stack is Empty" << endl;
                else
                    cout << "Top: " << stack[top] << endl;
            }
        }
    }

    return 0;
}