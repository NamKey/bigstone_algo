//
// Created by 남기륭 on 2022/10/19.

// 5 3 1
//1 6
//3 5
//2 8
//

#include <iostream>

using namespace std;

int price[3];

int parking_time[104];

int startTime;
int endTime;
int priceSum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> price[0] >> price[1] >> price[2];

    for (int i = 0; i < 3; ++i) {
        cin >> startTime >> endTime;

        for (int j = startTime; j < endTime; ++j) {
            parking_time[j]++;
        }
    }

    for (int i = 1; i < 100; ++i) {
        int count = parking_time[i];
        priceSum += price[count - 1] * count;
    }

    cout << priceSum;

    return 0;
}