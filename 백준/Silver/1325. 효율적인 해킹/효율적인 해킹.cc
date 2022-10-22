#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> clusters[10000];
bool visited[10004];

int N, M;
int maxConnection;

int dfs(int here) {

    visited[here] = true;

    int ret = 0;
    int count = 0;
    for (const auto &there: clusters[here]) {
        if (visited[there]) {
            continue;
        }
        ret += dfs(there);
        count++;
    }

    if (count == 0) {
        return 1;
    }

    return ret + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    set<int> computerList;

    for (int i = 0; i < M; ++i) {
        int A;
        int B;

        cin >> A >> B;

        clusters[B].push_back(A);
        computerList.insert(A);
        computerList.insert(B);
    }

    vector<pair<int, int>> compConnectionPair;

    for (const auto &item: computerList) {
        fill(&visited[0], &visited[0] + 10004, 0);
        int b = dfs(item);
        compConnectionPair.emplace_back(item, b);
        maxConnection = max(maxConnection, b);
    }

    for (const auto &item: compConnectionPair) {
        if (item.second == maxConnection) {
            cout << item.first << '\n';
        }
    }
}