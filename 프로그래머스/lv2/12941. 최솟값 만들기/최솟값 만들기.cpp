#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), less<>());
    
    int sum = 0;
    
    for (int i = 0; i < A.size(); i++) {
        sum += A[i] * B[i];
    }    

    return sum;
}