#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1e9+7;
const int maxn = 5e7;
int dp[maxn];

int powmod(int a, int b){
    int result = 1;
    while (b){
        if (b & 1) result = (result * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }

    return result;
}

int modinv(int a){
    return powmod(a, mod-2);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    int k = n * (n+1) / 2;
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = k; j > -1; --j){
            if (j < i) continue;
            if (dp[j-i]) {
                dp[j] += dp[j-i];
                dp[j] %= mod;
            }
        }
    }

    if (k % 2) cout << 0;
    else cout << (dp[k/2]*modinv(2))%mod;
    return 0;
}