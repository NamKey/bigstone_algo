//
// Created by 남기륭 on 2022/10/20.
//

#include <iostream>

using namespace std;

int y, x, ret;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int map[104][104];
bool visited[104][104];

//5 5
//1 0 1 0 1
//1 1 0 0 1
//0 0 0 1 1
//0 0 0 1 1
//0 1 0 0 0

/**
 * 결국 연결된 Component 찾는 문제임
 * @param here
 */
void PreDfsBangu(pair<int, int> here) {
    cout << here.first << " : " << here.second << '\n';

    visited[here.first][here.second] = true;
    for (int i = 0; i < 4; ++i) {
        int ty = here.first + dy[i];
        int tx = here.second + dx[i];

        if (ty < 0 || tx < 0 || ty >= y || tx >= x) {
            continue;
        }

        if (map[ty][tx] != 1 || visited[ty][tx]) {
            continue;
        }

        PreDfsBangu({ty, tx});
    }

    return;
}

int main() {

    cin >> y >> x;

    for (int j = 0; j < y; ++j) {
        for (int i = 0; i < x; ++i) {
            cin >> map[j][i];
        }
    }

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            if (map[i][j] == 1 && !visited[i][j]) {
                ret++;
                PreDfsBangu({i, j});
            }
        }
    }

    cout << ret << '\n';
}