//
// Created by 남기륭 on 2022/10/21.
//
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int virusMap[10][10];
int visited[10][10];

vector<pair<int, int>> wallParticipant;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; ++i) {
        int ty = y + dy[i];
        int tx = x + dx[i];

        if (tx < 0 || ty < 0 || ty >= N || tx >= M) {
            continue;
        }

        if (!visited[ty][tx] && virusMap[ty][tx] < 1) {
            dfs(ty, tx);
        }
    }
}

int countArea() {

    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (virusMap[i][j] == 2) {
                dfs(i, j);
            }
        }
    }

    int nonVirusArea = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!visited[i][j] && virusMap[i][j] == 0) {
                nonVirusArea++;
            }
        }
    }

    return nonVirusArea;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> virusMap[i][j];

            if (virusMap[i][j] < 1) {
                wallParticipant.emplace_back(i, j);
            }
        }
    }

    int areaMax = -1;
    for (int i = 0; i < wallParticipant.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < j; ++k) {
                virusMap[wallParticipant[i].first][wallParticipant[i].second] = 1;
                virusMap[wallParticipant[j].first][wallParticipant[j].second] = 1;
                virusMap[wallParticipant[k].first][wallParticipant[k].second] = 1;

                areaMax = max(areaMax, countArea());

                virusMap[wallParticipant[i].first][wallParticipant[i].second] = 0;
                virusMap[wallParticipant[j].first][wallParticipant[j].second] = 0;
                virusMap[wallParticipant[k].first][wallParticipant[k].second] = 0;
            }
        }
    }

    cout << areaMax << '\n';
}