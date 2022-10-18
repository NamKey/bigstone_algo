//
// Created by 남기륭 on 2022/10/18.
//

#include "combination.h"
#include <iostream>

using namespace std;

namespace week1 {
    void NextCombination(int n, int k, int position, vector<int> &list) {
        if (k == list.size()) {
            for (const auto &item: list) {
                cout << item << " ";
            }
            cout << endl;
            return;
        }

        for (int i = position + 1; i < n; ++i) {
            list.push_back(i);
            NextCombination(n, k, i, list);
            list.pop_back();
        }
    }
}

