#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
const int maxb = 8;
const int INF = 1e18;

struct Element {
    int x, s[maxb];

    Element(){};
} a[maxn];

int dp[maxn][(1 << maxb)], pf[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, p, k; cin >> n >> p >> k;

    for (int i = 1; i <= n; ++i){
        cin >> a[i].x;
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < p; ++j) cin >> a[i].s[j];
    }

    for (int i = 0; i <= n; ++i){
        for (int j = 0; j < (1 << p); ++j){
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;

    sort(a+1, a+n+1, [](const Element &aa, const Element &bb){
        return aa.x > bb.x;
    });

    for (int i = 1; i <= n; ++i){
        for (int mask = 0; mask < (1 << maxb); ++mask){
            int aud = (i - 1) - __builtin_popcount(mask);

            int add = 0;
            if (aud < k) add = a[i].x;
            if (aud >= 0) dp[i][mask] = max(dp[i][mask], dp[i-1][mask] + add);

            for (int j = 0; j < p; ++j){
                if (mask & (1 << j)){
                    dp[i][mask] = max(dp[i][mask], dp[i-1][mask ^ (1 << j)] + a[i].s[j]);
                }
            }
        }
    }

    cout << dp[n][(1 << p) - 1];

    return 0;
}