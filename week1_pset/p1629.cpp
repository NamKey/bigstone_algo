//
// Created by 남기륭 on 2022/10/20.
//

#include <iostream>

using namespace std;

int a, b, c;
unsigned long long res;
/**
 * 시간 초과 해결 방법 생각 필요함
 * @return
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> a >> b >> c;

    res = a;
    for (int i = 0; i < b; ++i) {
        res = (res * a) % c;
    }

    cout << res << '\n';
}