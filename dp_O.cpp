#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 22;
int dp[(1 << 21)];
int a[maxn][maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    }
    
    dp[0] = 1;
    for (int mask = 0; mask < (1 << n); ++mask){
        for (int i = 0; i < n; ++i){
            int nmask = mask | (1 << i);
            if (nmask == mask) continue;

            int j = __builtin_popcount(nmask) - 1;
            if (a[i][j] == 0) continue;
            dp[nmask] += dp[mask];
            if (dp[nmask] >= mod) dp[nmask] -= mod;
        }
    }

    cout << dp[(1 << n) - 1];

    return 0;
}