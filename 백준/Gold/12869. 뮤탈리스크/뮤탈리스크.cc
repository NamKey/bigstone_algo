#include <iostream>
#include <queue>

using namespace std;

int N;

int input[3];
int hpMap[64][64][64];
int attack[6][3] = {
        {9, 3, 1},
        {9, 1, 3},
        {3, 1, 9},
        {3, 9, 1},
        {1, 3, 9},
        {1, 9, 3},
};

struct HpPos {
    int hpOne;
    int hpTwo;
    int hpThree;
};

void attackScv(int firstHp, int secondHp, int thirdHp) {
    hpMap[firstHp][secondHp][thirdHp] = 1;
    queue<HpPos> queue;
    HpPos hpPos{
            firstHp,
            secondHp,
            thirdHp
    };

    queue.push(hpPos);

    while (queue.size()) {
        int firstOne = queue.front().hpOne;
        int twoOne = queue.front().hpTwo;
        int threeOne = queue.front().hpThree;
        queue.pop();

        if (firstOne == 0 && twoOne == 0 && threeOne == 0) {
            break;
        }

        for (auto &i: attack) {
            int oneAttack = i[0];
            int twoAttack = i[1];
            int threeAttack = i[2];

            int hpOne = max(0, firstOne - oneAttack);
            int hpTwo = max(0, twoOne - twoAttack);
            int hpThree = max(0, threeOne - threeAttack);

            if (hpMap[hpOne][hpTwo][hpThree]) {
                continue;
            }

            hpMap[hpOne][hpTwo][hpThree] = hpMap[firstOne][twoOne][threeOne] + 1;
            HpPos newHpPos{
                    hpOne,
                    hpTwo,
                    hpThree
            };
            queue.push(newHpPos);
        }
    }


}

int main() {

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }

    attackScv(input[0], input[1], input[2]);

    cout << hpMap[0][0][0] - 1 << '\n';
}