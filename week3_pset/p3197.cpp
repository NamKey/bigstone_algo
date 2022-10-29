//
// Created by 남기륭 on 2022/10/29.
//
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

char iceMap[1504][1504];
int visited[1504][1504];

int row, col;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

vector<pair<int, int>> backjoPosV;

void printVisited() {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}

void printIceMap() {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << iceMap[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool bfs(pair<int, int> src, pair<int, int> tar, vector<pair<int, int>>& meltPos) {
    queue<pair<int, int>> queue;
    visited[src.first][src.second] = 1;
    queue.emplace(src.first, src.second);

    bool isReachable = false;

    while(queue.size()) {
        int ny, nx;
        tie(ny, nx) = queue.front();
        queue.pop();

        if (visited[tar.first][tar.second]) {
            isReachable = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int ty = ny + dy[i];
            int tx = nx + dx[i];

            if (ty < 0 || tx < 0 || ty >= row || tx >= col || visited[ty][tx]) {
                continue;
            }

            if (iceMap[ty][tx] == 'X' && iceMap[ny][nx] == '.') {
                meltPos.emplace_back(ty, tx);
            }

            if (iceMap[ty][tx] == 'X') {
                continue;
            }

            visited[ty][tx] = visited[ny][nx] + 1;
            queue.emplace(ty, tx);
        }
    }

    return isReachable;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> row >> col;

    for (int i = 0; i < row; ++i) {
        string rowStr;
        cin >> rowStr;
        for (int j = 0; j < col; ++j) {
            iceMap[i][j] = rowStr[j];
            if (iceMap[i][j] == 'L') {
                backjoPosV.emplace_back(i, j);
            }
        }
    }

    int day = 0;
    while(true) {
        vector<pair<int, int>> meltPosV;
        memset(visited, 0, sizeof(visited));

        // 녹는 부분 찾기 + 백조 움직이기
        if (bfs(backjoPosV[0], backjoPosV[1], meltPosV)) {
            break;
        }

        memset(visited, 0, sizeof(visited));

        if (bfs(backjoPosV[1], backjoPosV[0], meltPosV)) {
            break;
        }

        // 녹이기
        for (const auto &item: meltPosV) {
            iceMap[item.first][item.second] = '.';
        }
        day++;
    }

    cout << day << '\n';
}