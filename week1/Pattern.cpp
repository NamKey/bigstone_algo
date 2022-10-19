//
// Created by 남기륭 on 2022/10/19.
//

#include "Pattern.h"

#include <vector>
#include <iostream>

using namespace std;

namespace week1 {
    void week1::ToDigit(int n, int digit) {
        vector<int> v;
        while (n > 1) {
            v.push_back(n % digit);
            n /= digit;
        }
        if (n == 1) {
            v.push_back(1);
        }

        reverse(v.begin(), v.end());

        for (int a: v) {
            if (a >= 10) {
                cout << char(a + 55);
            } else {
                cout << a;
            }
        }
    }

    void week1::RotateLeft90(vector<vector<int>> &key) {
        int m = key.size();

        vector<vector<int>> temp(m, vector<int>(m, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                temp[i][j] = key[j][m - i - 1];
            }
        }

        key = temp;
   }

    void week1::RotateRight90(vector<vector<int>> &key) {
        int m = key.size();

        vector<vector<int>> temp(m, vector<int>(m, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                temp[i][j] = key[m - j - 1][i];
            }
        }

        key = temp;
    }
}


