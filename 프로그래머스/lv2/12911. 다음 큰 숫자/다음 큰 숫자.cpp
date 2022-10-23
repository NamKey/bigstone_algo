#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> changeToDigitCount(int n, int radix) {
    vector<int> res;
        
    while (n > 1) {
        res.push_back(n % radix);
        n /= radix;
    }
    if (n == 1) {
        res.push_back(1);
    }
    reverse(res.begin(), res.end());
    
    return res;
}

int countOne(vector<int> v) {
    int count = 0;
    for (const auto item : v) {
        if (item == 1) {
            count++;
        }
    }
    
    return count;
}

int solution(int n) {
    vector<int> v = changeToDigitCount(n, 2);
    int stdCount = countOne(v);
        
    int nextNum = n + 1;
    for (;;++nextNum) {
        vector<int> v = changeToDigitCount(nextNum, 2);
        int count = countOne(v);
        
        if (stdCount == count) {
            break;
        }
    }
    
    return nextNum;
}