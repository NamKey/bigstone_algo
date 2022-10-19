//
// Created by 남기륭 on 2022/10/19.
//

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int n = 9;
int k = 7;
int a[9];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    do {
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += a[i];
        }

        if (sum == 100) {
            break;
        }
    } while (next_permutation(a, a + 9));

    for (int i = 0; i < k; ++i) {
        cout << a[i] << '\n';
    }

    return 0;
}