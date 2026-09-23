#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 20;

int dp[maxn][1 << maxn];

vector<vector<int>> adj;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, m; cin >> n >> m;
    adj.assign(n, vector<int>());

    int x, y;
    for (int i = 0; i < m; ++i){
        cin >> x >> y;
        adj[x-1].push_back(y-1);
    }

    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;

    for (int mask = 1; mask < (1 << n); ++mask){
        for (int u = 0; u < n; ++u){
            if (mask & (1 << u)){
                if (dp[u][mask] == 0) continue;

                for (const int &v : adj[u]){
                    int nmask = mask | (1 << v);

                    if (nmask == mask) continue;
                    dp[v][nmask] += dp[u][mask];
                    if (dp[v][nmask] >= mod) {
                        dp[v][nmask] -= mod;
                    }
                }
            }
        }
    }

    cout << dp[n-1][(1 << n) - 1] << '\n';

    return 0;
}