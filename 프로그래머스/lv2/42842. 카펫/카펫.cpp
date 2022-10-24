#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> getTilePairs(int tileCount) {
    vector<pair<int, int>> pairs;
    
    for (int i = 3; i * i <= tileCount; i++) {
        if (tileCount % i == 0) {
            pairs.push_back({tileCount / i, i});
        }
    }
    
    return pairs;
    
}
vector<pair<int, int>> tilePair;

vector<int> solution(int brown, int yellow) {
    
    vector<pair<int, int>> pairs = getTilePairs(brown + yellow);
    vector<int> answer(2);
    
    for(const auto item: pairs) {
        if (item.first >= item.second && (item.first - 2) * (item.second - 2) == yellow) {
            answer[0] = item.first;
            answer[1] = item.second;
        }
    }        
    
    return answer;
}