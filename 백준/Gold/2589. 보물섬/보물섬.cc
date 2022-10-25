#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int width, height;
char bomulMap[50][50];
int bomulDistMap[50][50];

vector<pair<int, int>> landPairs;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {

    cin >> height >> width;

    for (int i = 0; i < height; ++i) {
        string lineStr;
        cin >> lineStr;
        for (int j = 0; j < lineStr.size(); ++j) {
            bomulMap[i][j] = lineStr[j];
            if (bomulMap[i][j] == 'L') {
                landPairs.emplace_back(i, j);
            }
        }
    }

    int maxDist = -987654321;
    for (const auto &item: landPairs) {
        queue<pair<int, int>> landQueue;
        bool visited[50][50];

        memset(bomulDistMap, 0, sizeof(bomulDistMap));
        memset(visited, 0, sizeof(visited));

        landQueue.emplace(item.first, item.second);
        visited[item.first][item.second] = true;

        int currentMaxDist = -987654321;
        while (landQueue.size()) {
            int x, y;
            tie(y, x) = landQueue.front();
            landQueue.pop();

            for (int i = 0; i < 4; ++i) {
                int ty = y + dy[i];
                int tx = x + dx[i];

                if (ty < 0 || tx < 0 || ty >= height || tx >= width || bomulDistMap[ty][tx] > 0 || bomulMap[ty][tx] == 'W') {
                    continue;
                }

                if (visited[ty][tx] != 0) {
                    continue;
                }

                bomulDistMap[ty][tx] = bomulDistMap[y][x] + 1;
                visited[ty][tx] = true;
                currentMaxDist = max(bomulDistMap[ty][tx], currentMaxDist);
                landQueue.emplace(ty, tx);
            }
        }

        maxDist = max(currentMaxDist, maxDist);
    }

    cout << maxDist << '\n';
}