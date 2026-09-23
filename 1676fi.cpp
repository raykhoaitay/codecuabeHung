#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
int par[maxn], sz[maxn], maxx = 0;

int find(int v){
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}

int joint(int a, int b){
    a = find(a);
    b = find(b);

    if (a == b) return 0;
    if (sz[a] < sz[b]) swap(a, b);

    par[b] = a;
    sz[a] += sz[b];
    maxx = max(maxx, sz[a]);

    return 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        par[i] = i;
        sz[i] = 1;
    }

    int part = n;
    while (m--){
        int x, y; cin >> x >> y;
        int rs = joint(x, y);
        if (rs) part--;
        cout << part << ' ' << maxx << '\n';
    }

    return 0;
}