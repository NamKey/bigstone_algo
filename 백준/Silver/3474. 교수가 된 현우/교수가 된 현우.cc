#include <iostream>

using namespace std;
int T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int input;
        cin >> input;

        int ret2 = 0;
        int ret5 = 0;

        for (int j = 2; j <= input; j=2*j) {
            ret2 += input/j;
        }

        for (int j = 5; j <= input; j=5*j) {
            ret5 += input/j;
        }

        cout << min(ret2, ret5) << '\n';
    }
}