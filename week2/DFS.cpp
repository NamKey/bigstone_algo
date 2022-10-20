//
// Created by 남기륭 on 2022/10/20.
//

#include "DFS.h"

#include <vector>

using namespace std;

void PreDfs(int visited[], vector<int> adj[], int here) {
    visited[here] = 1;

    for (int there: adj[here]) {
        if (visited[there]) {
            continue;
        }
        PreDfs(visited, adj, there);
    }
}

void PostDfs(int visited[], vector<int> adj[], int here) {
    if (visited[here]) {
        return;
    }

    visited[here] = 1;
    for (int there: adj[here]) {
        PostDfs(visited, adj, there);
    }
}
