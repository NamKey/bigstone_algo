#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> sStack;
    for (const auto item: s) {
        if (!sStack.empty() && sStack.top() == '(' && item == ')') {
            sStack.pop();
        } else {
            sStack.push(item);
        }
    }
    
    if (sStack.empty()) {
        return true;    
    } else {
        return false;
    }
}