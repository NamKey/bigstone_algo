//
// Created by 남기륭 on 2022/10/19.
//

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string input;
bool isPalindrome;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> input;
    string temp = input;

    reverse(temp.begin(), temp.end());

    if (temp == input) {
        isPalindrome = true;
    } else {
        isPalindrome = false;
    }

    cout << isPalindrome;
    return 0;
}