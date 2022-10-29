#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int minVal = 987654321;
int maxVal = -987654321;

vector<int> split(string str, string delimeter) {
    vector<int> v;
    int pos;
    while((pos = str.find(delimeter)) != string::npos) {
        string token = str.substr(0, pos);
        int intVal = atoi(token.c_str());
        minVal = min(minVal, intVal);
        maxVal = max(maxVal, intVal);
        v.push_back(intVal);
        str.erase(0, pos + 1);
    }
    int intVal = atoi(str.c_str());
    minVal = min(minVal, intVal);
    maxVal = max(maxVal, intVal);
    
    v.push_back(atoi(str.c_str()));

    return v;
}

string solution(string s) {
    split(s, " ");
    string answer = to_string(minVal) + " " + to_string(maxVal);
    return answer;
}