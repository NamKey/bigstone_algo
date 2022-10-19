#include <iostream>

using namespace std;

string inputStr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    getline(cin, inputStr);

    for (int i = 0; i < inputStr.size(); ++i) {
        char& c = inputStr[i];
        if (isupper(c)) {
            if (c + 13 > 'Z') c = c + 13 -26;
            else c += 13;
        } else if (islower(c)) {
            if (c + 13 > 'z') c = c + 13 -26;
            else c += 13;
        }
    }

    cout << inputStr;
}