#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

vector<string> split(string input, string delimeter) {
    vector<string> ret;
    long long pos = 0;

    string token = "";
    while ((pos = input.find(delimeter)) != string::npos) {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimeter.size());
    }
    ret.push_back(input);

    return ret;
}

bool custom_compare(int a, int b) {
    return a > b;
}

struct Point {
    int x, y;

    Point() : x(-1), y(-1) {}

    Point(int x, int y) : x(x), y(y) {}

    bool operator<(const Point &a) const {
        if (x == a.x) {
            return y < a.y;
        }
        return x < a.x;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;

    // string
    string str = "Hello, World";

    // split
    vector<string> vector = split(str, " ");

    // pair
    pair<int, int> pi;

    pi = {1, 2};
    int a = 6;
    int b = 5;
    tie(a, b) = pi;

    cout << a << " " << b << endl;

    // sort
    std::vector<int> sortVector(10, 0);

    for (int i = 0; i < sortVector.size(); ++i) {
        sortVector[i] = i + random();
    }


    // custom compare sort lhs, rhs
    // lhs > rhs 내림차순, lhs < rhs 오름차순
    sort(sortVector.begin(), sortVector.end(), custom_compare);

    for (const auto &item: sortVector) {
        cout << item << " ";
    }

    cout << endl;

    // map - 기본적으로 정렬되는 map - O(logN)
    map<string, int> mp;
    mp["test1"] = 4;

    for (auto item: mp) {
        cout << item.first << ", " << item.second << "\n";
    }

    // set - map과 같음
    // multiset - 정렬되는 set, 중복 가능
    // stack, queue

    // priority queue - 내부는 heap으로 구현
    // - priority queue<자료형, 구현체, 비교연산자>
    // - priority_queue<Point>
    // - Custom 정렬 일시에는 반대로 부호해줘야됨
    priority_queue<int, std::vector<int>, std::greater<>> pq;

    // struct
    Point point;
    cout << point.x << ":" << point.y << endl;

    return 0;
}


