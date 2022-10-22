//
// Created by 남기륭 on 2022/10/22.
//

#include <iostream>
#include <stack>

using namespace std;
int N;
int arr[1000004];
int ret[1000004];

int main() {

    cin >> N;

    stack<int> okenStack;

    fill(&ret[0], &ret[0] + 1000004, -1);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];

        while (!okenStack.empty() && arr[okenStack.top()] < arr[i]) {
            ret[okenStack.top()] = arr[i];
            okenStack.pop();
        }

        okenStack.push(i);
    }

    for (int i = 0; i < N; ++i) {
        cout << ret[i] << ' ';
    }
}