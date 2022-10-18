//
// Created by 남기륭 on 2022/10/18.
//

#include "permutation.h"
#include <iostream>
#include <vector>

using namespace std;

namespace week1 {
    void nextPermutation(int n, int r, int depth, vector<int> &list) {
        if (r == depth) {
            for (const auto &item: list) {
                cout << item << " ";
            }
            cout << endl;
            return;
        }

        for (int i = depth; i < n; ++i) {
            swap(list[i], list[depth]);
            nextPermutation(n, r, depth + 1, list);
            swap(list[i], list[depth]);
        }
    }
}

