//
// Created by 남기륭 on 2022/10/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> numStrV;

int compare(string lhs, string rhs) {
    if (lhs.size() == rhs.size()) return lhs < rhs;

    return lhs.size() < rhs.size();
}

void split(string word, char delimeter, vector<string> &nums) {
    int pos;
    while ((pos = word.find(delimeter)) != string::npos) {
        string numStr = word.substr(0, pos);

        if (!numStr.empty()) {
            while (numStr.size() > 1 && numStr[0] == '0') {
                numStr.erase(0, 1);
            }
            nums.push_back(numStr);
        }

        word.erase(0, pos + 1);
    }

    if (word.empty()) {
        return;
    }

    while (word.size() > 1 && word[0] == '0') {
        word.erase(0, 1);
    }

    nums.push_back(word);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;

        for (int j = 0; j < word.size(); ++j) {
            if (isalpha(word[j])) {
                word[j] = '-';
            }
        }

        split(word, '-', numStrV);
    }

    sort(numStrV.begin(), numStrV.end(), compare);

    for (const auto &item: numStrV) {
        cout << item << '\n';
    }
}