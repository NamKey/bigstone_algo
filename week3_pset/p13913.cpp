//
// Created by 남기륭 on 2022/10/27.
//
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int visited[200004];
int trace[200004];

int N, K;

int main() {
    cin >> N >> K;

    visited[N] = 1;
    queue<int> queue;
    queue.push(N);

    while (queue.size()) {
        int here = queue.front();
        queue.pop();

        if (here == K) {
            break;
        }

        for (int next: {here - 1, here + 1, 2 * here}) {
            if (next < 0 || next >= 200000 || visited[next]) {
                continue;
            }

            visited[next] = visited[here] + 1;
            queue.push(next);
            trace[next] = here;
        }
    }

    vector<int> traceV;
    for(int i = K; i != N; i = trace[i]) {
        traceV.push_back(i);
    }
    traceV.push_back(N);
    reverse(traceV.begin(), traceV.end());

    cout << visited[K] - 1 << '\n';

    for(const auto item: traceV) {
        cout << item << ' ';
    }
}