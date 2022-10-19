//
// Created by 남기륭 on 2022/10/19.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int inputInt;
string inputStr;
vector<string> strArray;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> inputInt;
    cin >> inputStr;

    for (int i = 0; i < inputInt; ++i) {
        string testStr;
        cin >> testStr;
        strArray.push_back(testStr);
    }

    long pos = inputStr.find('*');

    string prefix = inputStr.substr(0, pos);
    string suffix = inputStr.substr(pos + 1);

    for (const auto &item: strArray) {
        if (prefix.size() + suffix.size() > item.size()) {
            cout << "NE" << '\n';
            continue;
        }

        if ((prefix == item.substr(0, prefix.size())) && (suffix == item.substr(item.size() - suffix.size()))) {
            cout << "DA" << '\n';
        } else {
            cout << "NE" << '\n';
        }
    }

    return 0;
}