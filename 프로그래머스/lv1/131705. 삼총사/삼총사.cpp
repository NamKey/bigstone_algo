#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ret;
int n;
int k;
vector<int> list;

void combination(int position, vector<int>& list, vector<int> number) {
    if (k == list.size()) {
        int sum = 0;
        for (auto item:list) {
            sum += item;
        }
        
        if (sum == 0) {
            ret++;    
        }        
        return;
    }
    
    for (int i = position + 1; i < n; i++) {
        list.push_back(number[i]);
        combination(i, list, number);
        list.pop_back();
    }
}

int solution(vector<int> number) {  
    n = number.size();
    k = 3;
    combination(-1, list, number);
    return ret;
}