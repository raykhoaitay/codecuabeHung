#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
const int maxm = 2e5+10;

struct Edge {
    int x, y, d;
} e[maxm];

int par[maxn], sz[maxn];

int find(int v){
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);

    if (a == b) return;
    if (sz[b] > sz[a]) swap(a, b);

    par[b] = a;
    sz[a] += sz[b];
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

    for (int i = 1; i <= m; ++i){
        cin >> e[i].x >> e[i].y >> e[i].d;
    }

    sort(e+1, e+1+m, [](const Edge &aa, const Edge &bb){
        return aa.d < bb.d;
    });

    int cow = 0, cost = 0;
    for (int i = 1; i <= m; ++i){
        if (cow == n) break;

        if (find(e[i].x) != find(e[i].y)){
            cost += e[i].d;
            cow++;
            join(e[i].x, e[i].y);
        }
    }

    if (cow < n-1){
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << cost << '\n';

    return 0;
}