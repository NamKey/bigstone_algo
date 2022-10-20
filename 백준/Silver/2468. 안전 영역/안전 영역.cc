#include <iostream>

using namespace std;

int N;

int waterMap[104][104];
bool visited[104][104];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int waterStage) {
    visited[y][x] = true;

    for (int i = 0; i < 4; ++i) {
        int ty = y + dy[i];
        int tx = x + dx[i];

        if (ty < 0 || tx < 0 || ty >= N || tx >= N) {
            continue;
        }

        if (visited[ty][tx]) {
            continue;
        }

        if (waterMap[ty][tx] > waterStage) {
            dfs(ty, tx, waterStage);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int stageMax = -1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> waterMap[i][j];
            if (waterMap[i][j] > stageMax) {
                stageMax = waterMap[i][j];
            }
        }
    }

    int retMax = -1;
    for (int k = 0; k < stageMax; ++k) {
        int regionCount = 0;
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!visited[i][j] && waterMap[i][j] > k) {
                    dfs(i, j, k);
                    regionCount++;
                }
            }
        }
        retMax = max(retMax, regionCount);
    }

    cout << retMax << '\n';
}