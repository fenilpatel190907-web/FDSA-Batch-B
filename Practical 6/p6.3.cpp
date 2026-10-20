
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {
        if (isspace(ch))
            continue;

        if (isalnum(ch)) {
            postfix += ch;
            postfix += ' ';
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }
        else {
            while (!s.empty() && s.top() != '(' &&
                   (precedence(s.top()) > precedence(ch) ||
                   (precedence(s.top()) == precedence(ch) && ch != '^'))) {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty()) {
        if (s.top() != '(') {
            postfix += s.top();
            postfix += ' ';
        }
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;

    cout << "Enter infix expression: ";
    getline(cin, infix);

    cout << "Postfix expression: "
         << infixToPostfix(infix) << endl;

    return 0;
}
