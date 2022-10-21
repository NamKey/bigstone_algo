#include <iostream>
#include <stack>

using namespace std;

int main() {
    string lineStr;
    while (getline(cin, lineStr)) {

        if (lineStr[0] == '.') break;

        stack<char> parenthesisStack;
        for (const auto &item: lineStr) {
            if (isalpha(item) || item == ' ' || item == '.') continue;

            if (!parenthesisStack.empty() && parenthesisStack.top() == '(' && item == ')') {
                parenthesisStack.pop();
            } else if (!parenthesisStack.empty() && parenthesisStack.top() == '[' && item == ']') {
                parenthesisStack.pop();
            } else {
                parenthesisStack.push(item);
            }
        }

        if (parenthesisStack.empty()) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }
}