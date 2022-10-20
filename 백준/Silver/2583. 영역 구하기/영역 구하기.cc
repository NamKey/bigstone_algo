#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
int floodMap[104][104];
bool visited[104][104];
vector<int> areaVector;
int ret;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int &t) {
    visited[y][x] = true;

    for (int i = 0; i < 4; ++i) {
        int ty = y + dy[i];
        int tx = x + dx[i];

        if (ty < 0 || tx < 0 || ty >= N || tx >= M) {
            continue;
        }

        if (visited[ty][tx] || floodMap[ty][tx] != 0) {
            continue;
        }

        dfs(ty, tx, ++t);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 0; i < K; ++i) {
        int leftX = 0;
        int leftY = 0;
        int rightX = 0;
        int rightY = 0;

        cin >> leftX >> leftY >> rightX >> rightY;

        for (int k = leftY; k < rightY; ++k) {
            for (int j = leftX; j < rightX; ++j) {
                floodMap[k][j] = 1;
            }
        }
    }

    int t = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!visited[i][j] && floodMap[i][j] == 0) {
                dfs(i, j, t);
                areaVector.push_back(t + 1);
                ret++;
                t = 0;
            }
        }
    }

    cout << ret << '\n';
    sort(areaVector.begin(), areaVector.end());
    for (const auto &item: areaVector) {
        cout << item << " ";
    }
}