//
// Created by 남기륭 on 2022/10/28.
//
#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int N, M;
int x1, y1, x2, y2;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

char classMap[301][301];
int visited[301][301];
int koongVisited[301][301];

void printClassMap() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << classMap[i][j] << ' ';
        }
        cout << '\n';
    }
}

void printKoongVisited() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << koongVisited[i][j] << ' ';
        }
        cout << '\n';
    }
}

void koong(int y, int x, int stepLimit) {
    queue<pair<int, int>> queue;
    queue.push({y, x});
    memset(koongVisited, 0, sizeof(koongVisited));

    while (queue.size()) {
        int ny, nx;
        tie(ny, nx) = queue.front();
        queue.pop();

        if (koongVisited[y][x] == stepLimit) {
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int ty = ny + dy[i];
            int tx = nx + dx[i];

            if (ty < 0 || tx < 0 || ty > N || tx > M || koongVisited[ty][tx]) {
                continue;
            }

            if (classMap[ty][tx] == '1') {
                classMap[ty][tx] = '0';
            }

            koongVisited[ty][tx] = koongVisited[ny][nx] + 1;
            queue.push({ty, tx});
        }
    }
}

bool bfs(int y, int x) {
    queue<pair<int, int>> queue;
    queue.push({y, x});

    bool result = false;
    while (queue.size()) {
        int ny, nx;
        tie(ny, nx) = queue.front();
        queue.pop();

        if (ny == y2 - 1 && nx == x2 - 1) {
            result = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int ty = ny + dy[i];
            int tx = nx + dx[i];

            if (ty < 0 || tx < 0 || ty > N || tx > M || classMap[ty][tx] == '1' || visited[ty][tx]) {
                continue;
            }

            visited[ty][tx] = visited[ny][nx] + 1;
            queue.push({ty, tx});
        }
    }

    return result;
}

int main() {

    cin >> N >> M;

    cin >> y1 >> x1 >> y2 >> x2;

    for (int i = 0; i < N; ++i) {
        string rowStr;
        cin >> rowStr;
        for (int j = 0; j < M; ++j) {
            classMap[i][j] = rowStr[j];
        }
    }

    int stepLimit = 1;
    while (true) {
        if (bfs(y1 - 1, x1 - 1)) {
            break;
        } else {
            koong(y1 - 1, x1 - 1, stepLimit++);

            printKoongVisited();
            cout << '\n';
        }
    }

    cout << stepLimit << '\n';
}