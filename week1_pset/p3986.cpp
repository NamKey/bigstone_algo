//
// Created by 남기륭 on 2022/10/20.
//

#include <iostream>
#include <stack>

using namespace std;
int problemCount;
int ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> problemCount;

    for (int i = 0; i < problemCount; ++i) {
        string problem;
        cin >> problem;

        stack<char> charStack;

        for (const auto &item: problem) {
            if (charStack.size() && item == charStack.top()) {
                charStack.pop();
            } else {
                charStack.emplace(item);
            }
        }

        if (charStack.empty()) {
            ret++;
        }
    }

    cout << ret << '\n';
}