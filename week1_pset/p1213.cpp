//
// Created by 남기륭 on 2022/10/19.
//
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

string inputStr;
map<char, int> strMap;
bool isPalin;
bool IsPalindrome(string s) {
    string temp = s;
    std::reverse(temp.begin(), temp.end());
    if (s == temp) {
        return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> inputStr;

    do {
        if (IsPalindrome(inputStr)) {
            isPalin = true;
            break;
        }
    } while (next_permutation(inputStr.begin(), inputStr.end()));

    if (isPalin) {
        cout << inputStr << '\n';
    } else {
        cout << "I'm Sorry Hansoo" << '\n';
    }

    return 0;
}