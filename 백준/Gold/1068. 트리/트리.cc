#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[54];

int N;
int root;
int clearNodeNum;

int dfs(int here) {
    int ret = 0;
    int child = 0;

    for (const auto &there: tree[here]) {
        if (there == clearNodeNum) continue;
        ret += dfs(there);
        child++;
    }
    if (child == 0) {
        return 1;
    }
    return ret;
}

int main() {

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int node;
        cin >> node;

        if (node == -1) {
            root = i;
        } else {
            tree[node].push_back(i);
        }
    }


    cin >> clearNodeNum;

    if (clearNodeNum == root) {
        cout << '0' << '\n';
        return 0;
    }

    cout << dfs(root) << '\n';
}