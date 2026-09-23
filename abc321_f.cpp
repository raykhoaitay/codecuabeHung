#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 998244353;
const int maxn = 5500;
int dp[maxn];
int q, k;

void add(int x){
    for (int i = k; i-x >= 0; --i){
        if (dp[i-x]){
            dp[i] += dp[i-x];
            dp[i] %= mod;
        }
    }
}

void take(int x){
    for (int i = 0; i+x <= k; ++i){
        dp[i+x] -= dp[i];
        dp[i+x] = (dp[i+x] + mod) % mod;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    cin >> q >> k;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    while (q--){
        string type;
        int x; cin >> type >> x;

        if (type == "+") add(x);
        else take(x);

        cout << dp[k] << '\n';
    }

    return 0;
}