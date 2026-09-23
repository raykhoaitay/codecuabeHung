#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;
int a[4], b[4];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    for (int i = 0; i < 4; ++i) cin >> a[i];
    for (int i = 0; i < 4; ++i) cin >> b[i];

    int x1 = min(a[0], b[0]),
    y1 = min(a[1], b[1]),
    x2 = max(a[2], b[2]),
    y2 = max(a[3], b[3]);

    int maxx = max(x2 - x1, y2 - y1);
    cout << maxx * maxx << '\n';

    return 0;
}