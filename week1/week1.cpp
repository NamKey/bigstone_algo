//
// Created by 남기륭 on 2022/10/18.
//

#include "permutation.h"
#include "combination.h"
#include "NumberTheory.h"
#include "Pattern.h"
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

    cout << endl;
    cout << endl;

    // 소수 판별하기
    bool b = week1::IsPrime(59);
    cout << b << endl;

    // lower_bound, upper bound
    vector<int> v;
    int a[5] = {1, 2, 2, 2, 3};
    for (int i = 0; i < 5; i++) {
        v.push_back(a[i]);
    }

    int x = 2;
    int c = (int) (upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x));
    int f = (int) (lower_bound(v.begin(), v.end(), x) - v.begin());
    int t = (int) (upper_bound(v.begin(), v.end(), x) - v.begin());

    cout << "x의 갯수 : " << c << endl;
    cout << "x가 처음 나타나는 시점 : " << f << endl;
    cout << "x가 뒤에서 처음 나타나기 전 인덱스 : " << t << endl;

    week1::ToDigit(10, 2);

    cout << endl;
    cout << endl;

    vector<vector<int>> matrix(4, vector<int>(4));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = i;
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;

    week1::RotateLeft90(matrix);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;

    week1::RotateRight90(matrix);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}