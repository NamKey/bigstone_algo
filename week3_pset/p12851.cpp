//
// Created by 남기륭 on 2022/10/27.
//
#include <iostream>
#include <queue>

using namespace std;
int visited[100004];
int cnt[100004];

int X, K;

void bfs(int here) {

    visited[here] = 1;
    cnt[here] = 1;
    queue<int> queue;
    queue.push(here);

    while (queue.size()) {
        int there = queue.front();
        queue.pop();

        for (int i = 0; i < 3; ++i) {
            int next = there;

            if (i == 0) {
                next += 1;
            } else if (i == 1) {
                next -= 1;
            } else if (i == 2) {
                next *= 2;
            }

            if (next < 0 || next > 100000) {
                continue;
            }

            if (!visited[next]) {
                visited[next] = visited[there] + 1;
                cnt[next] += cnt[there];
                queue.push(next);
            } else if (visited[next] == visited[there] + 1) {
                cnt[next] += cnt[there];
            }
        }
    }
}

int main() {
    cin >> X >> K;

    bfs(X);

    cout << visited[K] - 1 << '\n';
    cout << cnt[K] << '\n';
}