//
// Created by 남기륭 on 2022/10/21.
//

#include <iostream>
#include <utility>

using namespace std;

int H;
int W;

char cloudMap[104][104];
int cloudDisMap[104][104];

int main() {
    cin >> H >> W;

    for (int i = 0; i < H; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < W; ++j) {
            cloudMap[i][j] = line[j];

            if (cloudMap[i][j] == 'c') {
                cloudDisMap[i][j] = 0;
            } else {
                cloudDisMap[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (cloudDisMap[i][j] == 0) {
                int cnt = 1;
                while (cloudDisMap[i][j + 1] == -1) {
                    cloudDisMap[i][j + 1] = cnt++;
                    j++;
                }
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cout << cloudDisMap[i][j] << " ";
        }

        cout << '\n';
    }
}