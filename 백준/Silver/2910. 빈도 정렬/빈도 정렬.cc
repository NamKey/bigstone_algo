#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
map<int, int> countMap;
map<int, int> orderMap;
vector<pair<int, int>> messagePair;

int compare(pair<int, int> lhs, pair<int, int> rhs) {
    if (countMap[lhs.first] == countMap[rhs.first]) {
        return orderMap[lhs.first] < orderMap[rhs.first];
    }

    return countMap[lhs.first] > countMap[rhs.first];
}

int main() {
    cin >> N >> C;

    for (int i = 0; i < N; ++i) {
        int message;
        cin >> message;

        messagePair.emplace_back(message, i + 1); // vector는 요소와 순서
        countMap[message]++; // map은 요소와 카운팅

        if (orderMap[message] == 0) {
            orderMap[message] = i + 1;
        }
    }

    sort(messagePair.begin(), messagePair.end(), compare);

    for (auto &item: messagePair) {
        cout << item.first << ' ';
    }
}