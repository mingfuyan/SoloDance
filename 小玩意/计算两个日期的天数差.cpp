/*
power by Solo_Dance
*/
#include <bits/stdc++.h>

int leap[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int aver[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return y % 4 == 0;
}

int diffTwoDates(int y1, int m1, int d1, int y2, int m2, int d2) {
    if (y1 == y2) {
        if (m1 == m2) return d2 - d1;
        int ans = 0;
        if (isLeap(y1)) {
            ans += leap[m1] - d1 + d2;
            for (int i = m1 + 1; i < m2; ++i) ans += leap[i];
        } else {
            ans += aver[m1] - d1 + d2;
            for (int i = m1 + 1; i < m2; ++i) ans += aver[i];
        }
        return ans;
    }
    int ans = 0;
    if (isLeap(y1)) {
        ans += leap[m1] - d1;
        for (int i = m1 + 1; i <= 12; ++i) ans += leap[i];
    } else {
        ans += aver[m1] - d1;
        for (int i = m1 + 1; i <= 12; ++i) ans += aver[i];
    }
    if (isLeap(y2)) {
        ans += d2;
        for (int i = 1; i < m2; ++i) ans += leap[i];
    } else {
        ans += d2;
        for (int i = 1; i < m2; ++i) ans += aver[i];
    }
    for (int i = y1 + 1; i < y2; ++i) {
        if (isLeap(i)) ans += 366;
        else ans += 365;
    }
    return ans;
}
