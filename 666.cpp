#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
int a[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    sort(a+1, a+n+1);
    int l, r;
    while (q--){
        cin >> l >> r;

        int ll = lower_bound(a+1, a+n+1, l) - a;
        int rr = upper_bound(a+1, a+n+1, r) - a;

        cout << rr - ll << '\n';
    }

    return 0;
}