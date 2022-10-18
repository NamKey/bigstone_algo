//
// Created by 남기륭 on 2022/10/18.
//

#include "permutation.h"
#include "combination.h"
#include "vector"
#include "iostream"
/**
 * 순열 / 조합
 * @return
 */

using namespace std;

int main() {

    vector<int> permutation;
    vector<int> recursivePermutation;
    vector<int> recursiveCombination;

    for (int i = 0; i < 3; ++i) {
        permutation.push_back(i);
        recursivePermutation.push_back(i);
    }

    // 가장 간단하게 순열 만들기
    do {
        for (const auto &item: permutation) {
            cout << item << " ";
        }
        cout << endl;
    } while (next_permutation(permutation.begin(), permutation.end()));

    cout << endl;
    cout << endl;

    // 다른언어에 구현안되어 있을수도 있으니 재귀 방식으로 nextPermutation
    week1::nextPermutation(recursivePermutation.size(), recursivePermutation.size(), 0, recursivePermutation);

    cout << endl;
    cout << endl;

    week1::NextCombination(5, 3, -1, recursiveCombination);
}