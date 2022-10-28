//
// Created by 남기륭 on 2022/10/28.
//
#include <iostream>
#include <queue>

using namespace std;

const int maxN = 500000;
int N, K;
int visited[maxN + 1];
int kpos[maxN + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    if (N == K) {
        cout << 0 << '\n';
        return 0;
    }

    if (K >= maxN) {
        cout << -1 << '\n';
        return 0;
    }

    int stackSum = 0;
    for (int i = 1;; ++i) {
        if (K + stackSum > maxN) {
            break;
        }
        stackSum += i;
        kpos[K + stackSum] = i;
    }

    queue<int> queue;
    queue.push(N);

    int ret = 0;
    while (queue.size()) {
        int here = queue.front();
        queue.pop();

        if (kpos[here] > 0 && kpos[here] == visited[here]) {
            if (here > maxN) {
                ret = -1;
            } else {
                ret = visited[here];
            }

            break;
        }

        for (int next: {here - 1, here + 1, 2 * here}) {
            if (next < 0 || next > maxN || visited[next]) {
                continue;
            }

            visited[next] = visited[here] + 1;
            queue.push(next);
        }
    }

    cout << ret << '\n';
}