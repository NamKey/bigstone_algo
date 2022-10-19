//
// Created by 남기륭 on 2022/10/19.
//

#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

int n = 9;
int k = 7;
int a[9];
int total;
pair<int, int> ret;

//20
//7
//23
//19
//10
//15
//25
//8
//13

void solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (total - a[i] - a[j] == 100) {
                ret = {i, j};
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
    }
    sort(a, a + n);

    solve();

    vector<int> list;
    for (int i = 0; i < n; ++i) {
        if (i == ret.first || i == ret.second) continue;

        list.push_back(a[i]);
    }

    sort(list.begin(), list.end());

    for (const auto &item: list) {
        cout << item << '\n';
    }
    return 0;
}