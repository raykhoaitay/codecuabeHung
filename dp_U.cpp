// #include <bits/stdc++.h>

// #define int long long
// using namespace std;

// void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
// void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

// int mod = 1000000007;
// const int maxn = 18;
// vector<int> dp(1 << maxn, 0);
// int a[maxn][maxn];

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     #ifndef ONLINE_JUDGE
//         ray();
//     #endif

//     int n; cin >> n;
//     for (int i = 0; i < n; ++i){
//         for (int j = 0; j < n; ++j){
//             cin >> a[i][j];
//         }
//     }

//     dp[0] = 0;

//     for (int mask = 1; mask < (1 << n); ++mask){
//         for (int smask = mask; smask; smask = (smask - 1) & mask){
//             dp[mask] = max(dp[mask], dp[smask] + dp[(~smask) & mask]);
//         }

//         int cost = 0;
//         for (int i = 0; i < n; ++i){
//             if (mask & (1 << i)){
//                 for (int j = i; j < n; ++j){
//                     if (mask & (1 << j)){
//                         cost += a[i][j];
//                     }
//                 }
//             }
//         }

//         dp[mask] = max(dp[mask], max(0LL, cost));
//     }

//     cout << dp[(1 << n) - 1];
//     return 0;
// }

#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 18;

int dp[1 << maxn];
vector<int> cost(1 << maxn, -1e9+7);
int a[maxn][maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];

    cost[0] = 0;
    for (int mask = 0; mask < (1 << n); ++mask){
        for (int i = 0; i < n; ++i){
            int nmask = mask | (1 << i);
            if (nmask == mask) continue;
            if (cost[nmask] != (-1e9+7)) continue;

            cost[nmask] = cost[mask];
            for (int j = 0; j < n; ++j){
                if (mask & (1 << j)){
                    cost[nmask] += a[i][j];
                }
            }
        }
    }
    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); ++mask){
        for (int submask = mask; submask; submask = (submask - 1) & mask){
            int subset = mask ^ submask;
            dp[mask] = max(dp[mask], dp[submask] + dp[subset]);
        }

        dp[mask] = max(max(cost[mask], 0LL), dp[mask]);
    }

    cout << dp[(1 << n) - 1];
    return 0;
}