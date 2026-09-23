#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 5010;

int dp[maxn][maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; ++i){
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; ++i){
        dp[i][0] = i;
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            int hihi;

            if (s[i-1] == t[j-1]) hihi = min(dp[i-1][j-1] - 1, min(dp[i][j-1], dp[i-1][j]));
            else hihi = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));

            dp[i][j] = hihi + 1;
        }
    }

    cout << dp[n][m];
    return 0;
}