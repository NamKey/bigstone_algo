//
// Created by 남기륭 on 2022/10/19.
//
#include <iostream>
#include <vector>

using namespace std;

int player_count;
int player_map[26];
string ret;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> player_count;

    for (int i = 0; i < player_count; ++i) {
        string playername;
        cin >> playername;

        player_map[playername[0] - 'a']++;
    }

    for (int i = 0; i < 26; ++i) {
        if (player_map[i] >= 5) {
            ret += (char) (i + 'a');
        }
    }

    if (!ret.empty()) {
        cout << ret;
    } else {
        cout << "PREDAJA";
    }
    return 0;
}