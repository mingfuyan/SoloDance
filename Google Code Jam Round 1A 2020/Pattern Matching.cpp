/*
power by Solo_Dance
*/
#include <bits/stdc++.h>
#define eps 1e-8
using namespace std;
#define ms(a, b) memset((a), (b), sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int N = 1e5 + 5;
const int M = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const ll ll_max = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;

inline ll read() {
    ll res = 0;bool f = 0;char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = 1;ch = getchar();}
    while (ch <= '9' && ch >= '0') {res = (res << 3) + (res << 1) + ch - '0';ch = getchar();}
    return f ? (~res + 1) : res;
}

string s[100], qian[100], hou[100], ans;
int lef[100], rig[100];
int len[100];

bool isqian(int a, int b) {
    int l = qian[b].length();
    for (int i = 0; i < l; ++i)
        if (qian[a][i] != qian[b][i]) return false;
    return true;
}

bool ishou(int a, int b) {
    int l1 = hou[b].length();
    int l2 = hou[a].length();
    if (l1 == l2) {
        return hou[a] == hou[b];
    }
    while (l1 > 0) {
        l1--, l2--;
        if (hou[a][l2] != hou[b][l1]) return false;
    }
    return true;
}

int main() {
    int t = read(), ca = 1;

    while (t--) {
        int n = read();
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            len[i] = s[i].length();
            lef[i] = -1, rig[i] = len[i];
        }
        printf("Case #%d: ", ca++);

        // qian
        string tmp = "";
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < len[i]; ++j) {
                if (s[i][j] == '*') {
                    qian[i] = s[i].substr(0, j);
                    lef[i] = j;
                    if (tmp.length() < j) {
                        tmp = qian[i];
                        cnt = i;
                    }
                    break;
                }
            }
        }
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            if (!isqian(cnt, i)) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            puts("1*");
            continue;
        }

        ans = tmp;
        flag = 0;
        cnt = 0;
        tmp = "";
        // hou
        for (int i = 0; i < n; ++i) {
            for (int j = len[i] - 1; j >= 0; --j) {
                if (s[i][j] == '*') {
                    rig[i] = j;
                    hou[i] = s[i].substr(j + 1);
                    if (tmp.length() < hou[i].length()) {
                        tmp = hou[i];
                        cnt = i;
                    }
                    break;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!ishou(cnt, i)) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            puts("2*");
            continue;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = lef[i] + 1; j < rig[i]; ++j) {
                if (s[i][j] != '*') ans += s[i][j];
            }
        }
        ans += tmp;
        cout << ans << "\n";
    }


    return 0;
}
