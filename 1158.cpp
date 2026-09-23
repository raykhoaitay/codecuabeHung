#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1010;
int h[maxn], s[maxn], dp[100010];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = 1; i <= n; ++i) cin >> s[i];

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i){
        for (int j = k; j >= 0; --j){
            if (j < h[i]) continue;

            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }

    cout << dp[k];
    return 0;
}