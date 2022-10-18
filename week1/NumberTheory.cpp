//
// Created by 남기륭 on 2022/10/18.
//

#include "NumberTheory.h"

namespace week1 {
    int Gcd(int a, int b) {
        if (a == 0) {
            return b;
        }

        return (b % a, a);
    }

    int Lcm(int a, int b) {
        return (a * b) / Gcd(a, b);
    }

    vector<int> Era(int n) {
        vector<int> era;

        bool che[n];

        for (int i = 0; i < n; ++i) {
            che[i] = false;
        }

        for (int i = 2; i < n; i++) {
            if (che[i]) {
                continue;
            }
            for (int j = 2 * i; j < n; j += i) {
                che[j] = true;
            }
        }

        for (int i = 2; i < n; i++) {
            if (!che[n]) {
                era.push_back(i);
            }
        }

        return era;
    }

    bool IsPrime(int a) {
        if (a <= 1) {
            return false;
        }

        if (a == 2) {
            return true;
        }

        for (int i = 2; i * i <= a; ++i) {
            if (a % i == 0) {
                return false;
            }
        }

        return true;
    }
}