#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+5;
int pf[3][maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n; cin >> n;
    pf[0][0] = pf[1][0] = pf[2][0] = 0;

    for (int i = 1; i <= n; ++i){
        char c; cin >> c;
        pf[0][i] = ((c == 'S') ? 1 : 0) + pf[0][i-1];
        pf[1][i] = ((c == 'H') ? 1 : 0) + pf[1][i-1];
        pf[2][i] = ((c == 'P') ? 1 : 0) + pf[2][i-1];
    }

    int maxx = -1;
    for (int i = 1; i <= n; ++i){
        int h0 = pf[0][i] - pf[0][0],
        h1 = pf[1][i] - pf[1][0],
        h2 = pf[2][i] - pf[2][0],
        e0 = pf[0][n] - pf[0][i],
        e1 = pf[1][n] - pf[1][i],
        e2 = pf[2][n] - pf[2][i];

        maxx = max(maxx, max(h0 + max(e1, e2), max(h1 + max(e0, e2), h2 + max(e1, e0))));
    }

    cout << maxx;
    return 0;
}