//
// Created by 남기륭 on 2022/10/21.
//

#include <iostream>

using namespace std;

int N;

int scoreTime; // 분까지 초로 환산한 시각 1:00 -> 60, 10:30 -> 630
int latestScoreTime; // 가장 최근 Score가 난 시각

int winningTime1;
int winningTime2;

int winningTeam[2];

int main() {

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        int scoredTeam;
        int scoredMin;
        int scoredSec;
        scanf("%1d %2d:%2d", &scoredTeam, &scoredMin, &scoredSec);

        scoreTime = scoredMin * 60 + scoredSec;

        if (winningTeam[0] > winningTeam[1]) {
            winningTime1 += scoreTime - latestScoreTime;
        } else if (winningTeam[1] > winningTeam[0]) {
            winningTime2 += scoreTime - latestScoreTime;
        }

        if (scoredTeam == 1) {
            winningTeam[0]++;
        } else if (scoredTeam == 2) {
            winningTeam[1]++;
        }

        latestScoreTime = scoreTime;
    }

    if (winningTeam[0] > winningTeam[1]) {
        winningTime1 += 48 * 60 - latestScoreTime;
    } else if (winningTeam[1] > winningTeam[0]) {
        winningTime2 += 48 * 60 - latestScoreTime;
    }

    printf("%02d:%02d\n", winningTime1 / 60, winningTime1 % 60);
    printf("%02d:%02d\n", winningTime2 / 60, winningTime2 % 60);
}