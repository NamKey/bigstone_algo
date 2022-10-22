//
// Created by 남기륭 on 2022/10/22.
//

#include <iostream>
#include <vector>

using namespace std;


vector<pair<int, int>> cheeseConsume;
int cheeseMap[104][104];
int visited[104][104];

int N;
int M;

int consumeTime;
int latestCheeseRemained;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    visited[y][x] = 1;

    if (cheeseMap[y][x] == 1) {
        cheeseConsume.emplace_back(y, x);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int ty = y + dy[i];
        int tx = x + dx[i];

        if (ty < 0 || tx < 0 || ty >= N || tx >= M || visited[ty][tx]) {
            continue;
        }

        dfs(ty, tx);
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> cheeseMap[i][j];
        }
    }

    while (true) {
        latestCheeseRemained = 0;
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        cheeseConsume.clear();
        dfs(0, 0);

        for (const auto &item: cheeseConsume) {
            latestCheeseRemained++;
            cheeseMap[item.first][item.second] = 0;
        }

        bool isRemained = false;
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                if (cheeseMap[j][k] != 0) {
                    isRemained = true;
                }
            }
        }

        consumeTime++;

        if (!isRemained) {
            break;
        }
    }

    cout << consumeTime << '\n' << cheeseConsume.size() << '\n';
}