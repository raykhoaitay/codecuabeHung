#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

int powmod(int a, int b){
    int result = 1;

    while (b > 0){
        if (b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("ARMY.inp", "r", stdin);
    freopen("ARMY.out", "w", stdout);

    int n, m; cin >> m >> n;
    int d = 0, fact = 1;

    for (int i = 1; i <= n; ++i) fact = (fact * i) % mod;
    if (n == 2) d = 1;
    else {
        int prev = 0, now = 1;
        for (int i = 3; i <= n; ++i){
            d = (i - 1) * (prev + now);
            d %= mod;
            prev = now;
            now = d;
        }
    }

    cout << (fact * powmod(d, m-1)) % mod;
    return 0;
}