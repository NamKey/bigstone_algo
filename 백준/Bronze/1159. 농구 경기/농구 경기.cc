#include <iostream>
#include <map>
#include <vector>

using namespace std;

int player_count;
map<char, int> player_map;
vector<char> player_first_name;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> player_count;

    for (int i = 0; i < player_count; ++i) {
        string playername;
        cin >> playername;

        player_map[playername[0]]++;
    }

    for (const auto &item: player_map) {
        if (item.second >= 5) {
            player_first_name.push_back(item.first);
        }
    }

    if (player_first_name.empty()) {
        cout << "PREDAJA";
    } else {
        for (const auto &item: player_first_name) {
            cout << item;
        }
    }
    return 0;
}