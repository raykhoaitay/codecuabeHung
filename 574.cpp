#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 5e6+10;

bool dp[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int t, a, b; cin >> t >> a >> b;
    
    dp[0] = 1;
    for (int i = 1; i <= t; ++i){
        if (i >= a) dp[i] |= dp[i-a];
        if (i >= b) dp[i] |= dp[i-b];
    }

    for (int i = 1; i <= t; ++i){
        if (dp[i]) dp[(int)floor(i/2)] = 1;
    }

    for (int i = 1; i <= t; ++i){
        if (i >= a) dp[i] |= dp[i-a];
        if (i >= b) dp[i] |= dp[i-b];
    }

    int maxx;
    for (int i = t; i+1; --i){
        if (dp[i]){
            maxx = i;
            break;
        }
    }

    cout << maxx;
    return 0;
}