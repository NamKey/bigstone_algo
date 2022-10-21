//
// Created by 남기륭 on 2022/10/21.
//

#include <iostream>

using namespace std;

int moeumCount;
int jaeumCount;

bool hasMoeum;
bool isUnacceptSerial;
bool isTripleSerial;
bool isGood;

string word;

int main() {

    while (cin >> word) {

        if (word == "end") {
            break;
        }

        char prevChar = '\0';
        char curChar;
        hasMoeum = false;
        isTripleSerial = false;
        isUnacceptSerial = false;
        jaeumCount = 0;
        moeumCount = 0;

        for (const auto &item: word) {
            if (item == 'a' || item == 'e' || item == 'i' || item == 'o' || item == 'u') {
                hasMoeum = true;
                moeumCount++;
                jaeumCount = 0;
            } else {
                jaeumCount++;
                moeumCount = 0;
            }

            if (jaeumCount == 3 || moeumCount == 3) {
                isTripleSerial = true;
            }

            curChar = item;
            if (curChar == prevChar && (curChar != 'e' && curChar != 'o')) {
                isUnacceptSerial = true;
            }

            prevChar = curChar;
        }

        isGood = hasMoeum && !isTripleSerial & !isUnacceptSerial;

        if (isGood) {
            cout << "<" << word << ">" << " is acceptable.\n";
        } else {
            cout << "<" << word << ">" << " is not acceptable.\n";
        }
    }
}