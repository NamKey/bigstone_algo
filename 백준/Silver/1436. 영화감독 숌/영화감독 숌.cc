#include <iostream>

using namespace std;

int N;
int lastIndex;
int ret;

int main() {

    cin >> N;
    while (true) {
        if (to_string(ret).find("666") != string::npos) {
            lastIndex++;
        }

        if (lastIndex == N) {
            break;
        }

        ret++;
    }

    cout << ret << '\n';
}