#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5 + 5;
int a[maxn], pf[3][maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q; cin >> n >> q;
    pf[0][0] = pf[1][0] = pf[2][0] = 0;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pf[0][i] += ((a[i] == 1) ? 1 : 0) + pf[0][i-1];
        pf[1][i] += ((a[i] == 2) ? 1 : 0) + pf[1][i-1];
        pf[2][i] += ((a[i] == 3) ? 1 : 0) + pf[2][i-1];
    }

    while (q--){
        int l, r; cin >> l >> r;

        int r1 = pf[0][r] - pf[0][l-1], 
        r2 = pf[1][r] - pf[1][l-1],
        r3 = pf[2][r] - pf[2][l-1];

        cout << r1 << ' ' << r2 << ' ' << r3 << '\n';
    }
    
    return 0;
}