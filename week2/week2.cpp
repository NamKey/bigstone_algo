//
// Created by 남기륭 on 2022/10/20.
//

#include <iostream>
#include <vector>

#include "DFS.h"

using namespace std;


int main() {
    // 인접행렬 시간 복잡도 - O(V^2), 공간복잡도 - O(V^2)
    bool a[1004][1004];
    for (int i = 0; i < 1004; ++i) {
        for (int j = 0; j < 1004; ++j) {
            if (a[i][j]) {
                cout << i << "부터 " << j << "까지 경로가 있습니다.\n";
            }
        }
    }

    // 쓰이는 방법은 많음
    for (int i = 0; i < 1004; ++i) {
        for (int j = 0; j < 1004; ++j) {
            if (a[i][j]) {
                // dfs로 깊이 우선 탐색
                // bfs로 너비 우선 탐색
            }
        }
    }

    // 예를 들어 3에서 5번을 간다고 하면
    a[3][5] = true;

    // 인접리스트 시간복잡도 - O(V+E), 공간 복잡도 - O(V+E)
    vector<int> adj[1004]; // vector의 배열 형태로
    adj[1].push_back(2);

    for (int i = 0; i < 1004; ++i) {
        for (int there: adj[i]) {

        }

        // 같은 방식의 코드
        for (int j = 0; j < adj[j].size(); ++j) {
            int there = adj[i][j];
        }
    }

    // 3번에서 5번 가는 것 만들기
    adj[3].push_back(5);

    // 간선이 많으면 인접행렬, 적으면 인접 리스트

    // 탐색 방법

    // 방향 벡터
    // {y-1, x}, {y, x + 1}, {y + 1, x}, {y, x - 1}
    const int dy[] = {-1, 0, 1, 0};
    const int dx[] = {0, 1, 0, -1};

    int x = 1;
    int y = 1;
    // Q. 맵은 y는 0 이상 1000미만, x는 0이상 1000 미만 좌표를 가짐, {1, 1}의 4방향 좌표 나타내기
    for (int i = 0; i < 4; ++i) {
        int ty = y + dy[i];
        int tx = x + dx[i];
        cout << ty << " : " << tx << endl;
    }

    // Q. 맵은 y는 0 이상 1000미만, x는 0이상 1000 미만 좌표를 가짐, {1, 1}의 4방향 좌표 나타내기
    for (int i = 0; i < 4; ++i) {
        int ty = y + dy[i];
        int tx = x + dx[i];

        if (tx < 0 || ty < 0 || tx >= 1000 || ty >= 1000) {
            continue;
        }
        cout << ty << " : " << tx << endl;
    }

    // 인접리스트에서 탐색방법
    vector<int> adjsearch[1004];
    adjsearch[1].push_back(2);
    adjsearch[1].push_back(3);

    for (const auto there: adjsearch[1]) {
        cout << there << ' ';
    }

    // 깊이 우선 탐색(DFS)
    int visited[1004];
    vector<int> adjSearchDfs[1004];
    PreDfs(visited, adjSearchDfs, 10);


}