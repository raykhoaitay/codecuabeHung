#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e6+5;
int dp[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    fill(dp, dp+maxn, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= k; ++i){
        for (int j = 0; j < n; ++j){
            if (a[j] > i) break;

            dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }
    
    if (dp[k] < INT_MAX) cout << dp[k];
    else cout << -1;

    return 0;
}