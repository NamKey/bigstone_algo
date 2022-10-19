//
// Created by 남기륭 on 2022/10/19.
//
#include <iostream>
#include <map>

using namespace std;

int problemCount;
int clothesCount;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> problemCount;

    while (problemCount--) {
        cin >> clothesCount;

        map<string, int> clothesMap;

        for (int i = 0; i < clothesCount; ++i) {
            string clothesName = "";
            string clothesKind = "";
            cin >> clothesName >> clothesKind;

            clothesMap[clothesKind]++;
        }

        long long prob = 1;
        for (const auto &item: clothesMap) {
            prob *= (item.second + 1);
        }

        cout << prob - 1 << '\n';
    }

    return 0;
}