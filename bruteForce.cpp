#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 998244353;
const int maxn = 5e5+10;

int a[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];

    while (q--){
        int t, l, r, b, c; cin >> t;
        if (!t){
            cin >> l >> r >> b >> c;

            for (int i = l; i < r; ++i){
                a[i] = (b * a[i] + c) % mod;
            }
        }
        else {
            cin >> l >> r;

            int sum = 0;
            for (int i = l; i < r; ++i){
                sum += a[i];
                sum %= mod;
            }
            cout << sum << endl;
        }
    }

    return 0;
}