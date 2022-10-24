#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> strStack;
    for(const auto item : s) {
        if (!strStack.empty() && strStack.top() == item) {
            strStack.pop();
        } else {
            strStack.push(item);
        }
    }

    return strStack.empty();
}