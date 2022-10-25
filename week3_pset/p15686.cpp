//
// Created by 남기륭 on 2022/10/25.
//
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int chickenMap[50][50];
vector<pair<int, int>> homePosPairs;
vector<pair<int, int>> chickenShopPosPairs;
vector<vector<int>> chickenCombi;

void combi(int start, vector<int> list) {
    if (list.size() == M) {
        chickenCombi.emplace_back(list);
        return;
    }

    for (int i = start + 1; i < chickenShopPosPairs.size(); ++i) {
        list.push_back(i);
        combi(i, list);
        list.pop_back();
    }
}

int main() {

    cin >> N >> M;

    int minChickenDistance = 987654321;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> chickenMap[i][j];

            if (chickenMap[i][j] == 1) {
                homePosPairs.emplace_back(i, j);
            }
            if (chickenMap[i][j] == 2) {
                chickenShopPosPairs.emplace_back(i, j);
            }
        }
    }

    vector<int> v;
    combi(-1, v);

    for (vector<int> &chicken: chickenCombi) {
        int ret = 0;

        for (pair<int, int> &home: homePosPairs) {
            int minDist = 987654321;

            for (const auto &chickenIndex: chicken) {
                int chickenDist = abs(home.first - chickenShopPosPairs[chickenIndex].first) + abs(home.second - chickenShopPosPairs[chickenIndex].second);
                minDist = min(minDist, chickenDist);
            }

            ret += minDist;
        }

        minChickenDistance = min(minChickenDistance, ret);
    }

    cout << minChickenDistance << '\n';
}