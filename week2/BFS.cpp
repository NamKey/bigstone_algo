//
// Created by 남기륭 on 2022/10/20.
//

#include "BFS.h"

#include <queue>

using namespace std;

int visited[104][104];
int map[104][104];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void Bfs(queue<pair<int, int>> queue, pair<int, int> here, int m, int n) {

    visited[here.first][here.second] = 1;
    queue.push(here);

    while (queue.size()) {
        int y = 0;
        int x = 0;
        tie(y, x) = queue.front();
        queue.pop();
        for (int i = 0; i < 4; ++i) {
            int ty = y + dy[i];
            int tx = x + dx[i];

            if (tx < 0 || ty < 0 || tx >= m || ty >= n) {
                continue;
            }

            if (visited[ty][tx]) {
                continue;
            }

            visited[ty][tx] = visited[y][x] + 1;
            queue.push({ty, tx});
        }
    }
}