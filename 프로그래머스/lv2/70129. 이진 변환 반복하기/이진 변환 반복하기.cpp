#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 이진 변환 횟수, 제거된 모든 0의 갯수
vector<int> answer;

string split(string str, string delimeter) {
    string res = "";
    int pos;
    while ((pos = str.find(delimeter)) != string::npos) {
        string substr = str.substr(0, pos);
        res += substr;
        str.erase(0, pos + delimeter.length());

    }

    res += str;
    return res;
}

string changeToDigitCount(string str) {
    vector<int> res;
    string output = "";
    int size = str.size();

    while (size > 1) {
        res.push_back(size % 2);
        size /= 2;
    }

    if (size == 1) {
        res.push_back(1);
    }

    reverse(res.begin(), res.end());
    for (const auto item : res) {
        output += to_string(item);
    }
    return output;
}

vector<int> solution(string s) {
    answer.push_back(0);
    answer.push_back(0);
    string str = s;

    while (str.size() > 1) {
        int current = str.size();
        string res = split(str, "0");
        answer[1] += current - res.size();
        str = changeToDigitCount(res);
        answer[0]++;
    }

    return answer;
}