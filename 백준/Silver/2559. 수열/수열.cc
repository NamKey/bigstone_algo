#include <iostream>
#include <limits>

using namespace std;

int totalSize;
int windowSize;
int temperture[1000000];
int temp;

int main() {

    cin >> totalSize >> windowSize;

    long long max = std::numeric_limits<int>::lowest();
    for (int i = 1; i <= totalSize; ++i) {
        cin >> temp;
        temperture[i] = temperture[i - 1] + temp;
    }

    for (int i = windowSize; i <= totalSize; ++i) {
        long long sum = temperture[i] - temperture[i - windowSize];
        max = std::max(sum, max);
    }

    cout << max;
}