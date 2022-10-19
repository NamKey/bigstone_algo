//
// Created by 남기륭 on 2022/10/19.
// baekjoon
//

#include <iostream>

using namespace std;

int strArray[26];
string inputStr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> inputStr;

    for (char &item: inputStr) {
        strArray[item - 'a']++;
    }

    for (const auto &item: strArray) {
        cout << item << " ";
    }
}