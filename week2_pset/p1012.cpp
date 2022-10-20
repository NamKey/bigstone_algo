//
// Created by 남기륭 on 2022/10/20.
//

#include <iostream>
#include <algorithm>

using namespace std;

int testCount;
int mapWidth, mapHeight, cnt;

int globalMap[54][54];
bool visited[54][54];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    visited[y][x] = true;

    for (int i = 0; i < 4; ++i) {

        int ty = y + dy[i];
        int tx = x + dx[i];

        if (ty < 0 || tx < 0 || ty >= mapHeight || tx >= mapWidth) {
            continue;
        }

        if (visited[ty][tx] || globalMap[ty][tx] == 0) {
            continue;
        }

        dfs(ty, tx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> testCount;

    while (testCount--) {
        cin >> mapWidth >> mapHeight >> cnt;

        fill(&globalMap[0][0], &globalMap[0][0] + 54 * 54, 0);
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);

        for (int i = 0; i < cnt; ++i) {
            int x;
            int y;
            cin >> x >> y;

            globalMap[y][x] = 1;
        }

        int ret = 0;
        for (int i = 0; i < mapHeight; ++i) {
            for (int j = 0; j < mapWidth; ++j) {
                if (!visited[i][j] && globalMap[i][j] != 0) {
                    ret++;
                    dfs(i, j);
                }
            }
        }

        printf("%d\n", ret);
    }
}