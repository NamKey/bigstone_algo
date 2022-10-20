#include <iostream>
#include <string>

using namespace std;

int inputNum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (scanf("%d", &inputNum) != EOF) {
        int init = 1;
        int ret = 1;

        while (true) {
            if (init % inputNum != 0) {
                init = init * 10 + 1;
                init %= inputNum;
                ret++;
            } else {
                cout << ret << '\n';
                break;
            }
        }
    }
}