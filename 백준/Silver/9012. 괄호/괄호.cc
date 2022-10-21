#include <iostream>
#include <stack>

using namespace std;

int N;

int main() {

    cin >> N;

    for (int i = 0; i < N; ++i) {
        string parenthesis;
        cin >> parenthesis;

        stack<char> parenthStack;
        for (int j = 0; j < parenthesis.size(); ++j) {
            char b = parenthesis[j];
            if (!parenthStack.empty() && parenthStack.top() == '(' && b == ')') {
                parenthStack.pop();
            } else {
                parenthStack.push(b);
            }
        }

        if (parenthStack.empty()) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}