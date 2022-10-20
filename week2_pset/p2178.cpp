//
// Created by 남기륭 on 2022/10/20.
//

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int visited[104][104];
int maze[104][104];
queue<pair<int, int>> mazeQueue;
int width, height;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {
    scanf("%d %d", &height, &width);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            scanf("%1d", &maze[i][j]);
        }
    }

    visited[0][0] = 1;
    mazeQueue.push({0, 0});

    while (mazeQueue.size()) {
        int y = 0;
        int x = 0;
        tie(y, x) = mazeQueue.front();
        mazeQueue.pop();

        for (int i = 0; i < 4; ++i) {
            int ty = y + dy[i];
            int tx = x + dx[i];

            if (tx < 0 || ty < 0 || tx >= width || ty >= height) {
                continue;
            }

            if (maze[ty][tx] == 0 || visited[ty][tx] != 0) {
                continue;
            }

            visited[ty][tx] = visited[y][x] + 1;
            mazeQueue.push({ty, tx});
        }
    }

    cout << visited[height - 1][width - 1] << '\n';
}