#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

int a[maxn], dp[maxn][105];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    memset(dp, 0, sizeof(dp));
    if (a[1] == 0){
        for (int i = 1; i <= m; ++i) dp[1][i] = 1;
    }
    else dp[1][a[1]] = 1;

    for (int i = 2; i <= n; ++i){
        if (a[i] == 0){
            for (int j = 1; j <= m; ++j){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                dp[i][j] %= mod;
            }
        }
        else {
            int j = a[i];
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
            dp[i][j] %= mod;
        }
    }

    int mk = 0;
    for (int i = 1; i <= m; ++i){
        mk += (dp[n][i]);
        mk %= mod;
    }

    cout << mk;
    return 0;
}