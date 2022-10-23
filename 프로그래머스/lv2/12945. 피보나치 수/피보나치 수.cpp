#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    
    int prevPrev = 1;
    int prev = 1;
    int current = 0;
    int m = 1234567;
    for (int i = 3; i <= n; i++) {
        current = (prev + prevPrev) % m ;
        prevPrev = prev % m;
        prev = current % m;
    }
    
    return current;
}