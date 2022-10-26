#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int inguMap[50][50];
bool visited[50][50];

int N;
int L, R;
int sumIngu;

vector<pair<int, int>> nationPos;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int step = 0;

void dfs(int y, int x) {
    visited[y][x] = true;
    nationPos.emplace_back(y, x);

    for (int i = 0; i < 4; ++i) {
        int ty = y + dy[i];
        int tx = x + dx[i];

        if (ty < 0 || tx < 0 || ty >= N || tx >= N || visited[ty][tx]) {
            continue;
        }

        int diff = abs(inguMap[y][x] - inguMap[ty][tx]);
        if (diff < L || diff > R) {
            continue;
        }

        step++;
        sumIngu += inguMap[ty][tx];

        dfs(ty, tx);
    }
}

int main() {

    cin >> N >> L >> R;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> inguMap[i][j];
        }
    }

    int k = 0;
    while (true) {
        memset(visited, 0, sizeof(visited));

        step = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                sumIngu = 0;
                nationPos.clear();

                if (!visited[i][j]) {
                    sumIngu += inguMap[i][j];
                    dfs(i, j);
                }

                int averageIngu = sumIngu / (int)nationPos.size();

                for (const auto &item: nationPos) {
                    inguMap[item.first][item.second] = averageIngu;
                }
            }
        }

        if (step == 0) {
            break;
        }

        k++;
    }

    cout << k << '\n';
}