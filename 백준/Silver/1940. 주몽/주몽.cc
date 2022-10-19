#include <iostream>
#include <map>

using namespace std;

int totalCount;
int targetNumber;
map<int, int> joinMap;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> totalCount >> targetNumber;

    for (int i = 0; i < totalCount; ++i) {
        int join;
        cin >> join;
        joinMap[join]++;
    }

    int ret = 0;

    for (const auto &item: joinMap) {
        if (joinMap.find(targetNumber - item.first)->second == 1) {
            ret++;
        }
    }

    cout << ret / 2 << '\n';

    return 0;
}