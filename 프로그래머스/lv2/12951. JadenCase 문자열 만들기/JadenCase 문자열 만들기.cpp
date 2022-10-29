#include <string>
#include <vector>

using namespace std;

string solution(string s) {

    string answer = "";
    bool wordFlag = true;

    for(const auto item: s) {
        if (isalpha(item) && wordFlag) {
            answer += toupper(item);
            wordFlag = false;
        } else if(isalpha(item) && !wordFlag) {
            answer += tolower(item);
        } else if (item == ' ') {
            answer += " ";
            wordFlag = true;
        } else if (isdigit(item)) {
            answer += item;
            wordFlag = false;
        }
    }

    return answer;
}