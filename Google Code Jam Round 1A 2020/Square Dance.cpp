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
int r, c;
inline int _(int i, int j){
    if (i >= 1 && i <= r && j >= 1 && j <= c)
        return (i - 1) * c + j - 1;
    return -1;
}
int a[N];
struct link{
    int u, d, l, r;
}li[N];

queue<int>q1, q2, q3;
set<int>se;
int vis[N];
int main(){
    int t = read(), ca = 1;
    while(t--){
        while(!q1.empty()) q1.pop();
        r = read(), c = read();
        ll ans = 0, sum = 0;
        for (int i = 1; i <= r; ++i){
            for (int j = 1; j <= c; ++j){
                a[_(i, j)] = read();
                sum += a[_(i, j)];
                li[_(i, j)] = {_(i - 1, j), _(i + 1, j), _(i, j - 1), _(i, j + 1)};
                q1.push(_(i, j));
            }
        }
        ms(vis, 0);
        while(!q1.empty()){
            ans += sum;
            while(!q1.empty()){
                ll tmp = 0;
                int cnt = 0;
                int u = q1.front();q1.pop();
                if (vis[u] == 1) continue;
                if (li[u].u != -1) tmp += a[li[u].u], cnt++;
                if (li[u].d != -1) tmp += a[li[u].d], cnt++;
                if (li[u].l != -1) tmp += a[li[u].l], cnt++;
                if (li[u].r != -1) tmp += a[li[u].r], cnt++;
                if (1ll * cnt * a[u] < tmp){
                    sum -= a[u];
                    vis[u] = 1;
                    q3.push(u);
                }
            }

            while (!q3.empty()) {
                int u = q3.front(); q3.pop();
                if (li[u].u != -1) {
                    q1.push(li[u].u);
                    li[li[u].u].d = li[u].d;
                }
                if (li[u].d != -1) {
                    q1.push(li[u].d);
                    li[li[u].d].u = li[u].u;
                }
                if (li[u].l != -1) {
                    q1.push(li[u].l);
                    li[li[u].l].r = li[u].r;
                }
                if (li[u].r != -1) {
                    q1.push(li[u].r);
                    li[li[u].r].l = li[u].l;
                }
            }
        }
        printf("Case #%d: %lld\n", ca++, ans);
    }

    return 0;
}
