#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int R, C;
int INF = 987654321;
char mazeMap[1001][1001];
int manVisited[1001][1001];
int fireVisited[1001][1001];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {

    cin >> R >> C;

    pair<int, int> startPos;
    queue<pair<int, int>> fireQueue;
    fill(&fireVisited[0][0], &fireVisited[0][0] + 1001 * 1001, INF);
    for (int i = 0; i < R; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < C; ++j) {
            mazeMap[i][j] = row[j];
            if (mazeMap[i][j] == 'J') {
                startPos = {i, j};
            }

            if (mazeMap[i][j] == 'F') {
                fireVisited[i][j] = 1;
                fireQueue.emplace(i, j);
            }
        }
    }

    while (fireQueue.size()) {
        int fx = 0;
        int fy = 0;
        tie(fy, fx) = fireQueue.front();
        fireQueue.pop();

        for (int i = 0; i < 4; ++i) {
            int ty = fy + dy[i];
            int tx = fx + dx[i];

            if (ty < 0 || tx < 0 || ty >= R || tx >= C) {
                continue;
            }

            if (mazeMap[ty][tx] == '#' || fireVisited[ty][tx] != INF) {
                continue;
            }

            fireVisited[ty][tx] = fireVisited[fy][fx] + 1;
            fireQueue.push({ty, tx});
        }
    }

    queue<pair<int, int>> humanQueue;
    humanQueue.push(startPos);
    manVisited[startPos.first][startPos.second] = 1;
    bool canExit = false;
    int minExitTime = 0;

    while (humanQueue.size()) {
        int hx = 0;
        int hy = 0;
        tie(hy, hx) = humanQueue.front();
        humanQueue.pop();

        if (hy == 0 || hx == 0 || hy == R - 1 || hx == C - 1) {
            minExitTime = manVisited[hy][hx];
            canExit = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int ty = hy + dy[i];
            int tx = hx + dx[i];

            if (ty < 0 || tx < 0 || ty >= R || tx >= C || manVisited[ty][tx] > 0) {
                continue;
            }

            if (mazeMap[ty][tx] == '#') {
                continue;
            }

            if (fireVisited[ty][tx] <= manVisited[hy][hx] + 1) {
                continue;
            }

            manVisited[ty][tx] = manVisited[hy][hx] + 1;
            humanQueue.push({ty, tx});
        }
    }

    if (canExit) {
        cout << minExitTime << '\n';
    } else {
        cout << "IMPOSSIBLE" << '\n';
    }
}