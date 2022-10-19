//
// Created by 남기륭 on 2022/10/19.
//

#include <string>
#include <iostream>

using namespace std;

string input;
int startIndex;
int endIndex;
bool isPalindrome;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> input;

    startIndex = 0;
    endIndex = input.size() - 1;
    isPalindrome = true;

    while (startIndex <= endIndex) {

        if (input[startIndex] != input[endIndex]) {
            isPalindrome = false;
            break;
        }

        startIndex++;
        endIndex--;
    }

    cout << isPalindrome;
    return 0;
}