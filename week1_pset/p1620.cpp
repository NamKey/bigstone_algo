//
// Created by 남기륭 on 2022/10/19.
//

#include "cstdlib"
#include <iostream>
#include <map>

using namespace std;

int pocketCount;
int problemCount;


string pocketMon;
map<string, int> pocketMap;
map<int, string> pocketMap2;
string problemName;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> pocketCount >> problemCount;

    for (int i = 0; i < pocketCount; ++i) {
        cin >> pocketMon;
        pocketMap.emplace(pocketMon, i + 1);
        pocketMap2.emplace(i + 1, pocketMon);
    }

    for (int i = 0; i < problemCount; ++i) {
        cin >> problemName;

        if (std::atoi(problemName.c_str()) == 0) {
            cout << pocketMap[problemName] << '\n';
        } else {
            cout << pocketMap2[std::atoi(problemName.c_str())] << '\n';
        }
    }

    return 0;
}