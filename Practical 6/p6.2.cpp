
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Browser {
    stack<string> history;

public:
    void visit(string page) {
        history.push(page);
        display();
    }

    void back() {
        if (history.empty()) {
            cout << "Error: No page history" << endl;
            return;
        }

        history.pop();

        if (history.empty())
            cout << "No page open" << endl;
        else
            display();
    }

    void display() {
        if (history.empty()) {
            cout << "Current page: None" << endl;
        } else {
            cout << "Current page: " << history.top() << endl;
        }
    }
};

int main() {
    Browser b;

    b.visit("Google");
    b.visit("YouTube");
    b.visit("Wikipedia");
    b.back();
    b.back();
    b.back();
    b.back();

    return 0;
}
