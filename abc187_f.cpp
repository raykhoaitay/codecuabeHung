#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 20;

int adj[maxn];
int dp[(1 << maxn)];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, m; cin >> n >> m;

    memset(adj, 0, sizeof(adj));
    for (int i = 1; i <= m; ++i){
        int x, y; cin >> x >> y;
        x--; y--;

        adj[x] |= (1 << y);
        adj[y] |= (1 << x);
    }

    for (int mask = 1; mask < (1 << n); ++mask){
        int check = 0;
        for (int i = 0; i < n; ++i){
            if (__builtin_popcount(mask) < 2){
                dp[mask] = 1;
                continue;
            }

            if (mask & (1 << i)){
                if (((mask ^ (1 << i)) & adj[i]) == (mask ^ (1 << i))) continue;

                check = 1;
            }

        }

        if (check) dp[mask] = INT_MAX;
        else dp[mask] = 1;
    }

    for (int mask = 1; mask < (1 << n); ++mask){
        if (dp[mask] == 1) continue;

        for (int submask = mask; submask; submask = (submask - 1) & mask){
            int subset = mask ^ submask;

            dp[mask] = min(dp[mask], dp[submask] + dp[subset]);
        }
    }


    cout << dp[(1 << n) - 1];
    return 0;   
}