#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2005;

int a[maxn];
struct Edge {
    int x, y, w;

    Edge (int x, int y, int w): x(x), y(y), w(w) {};
};

int par[maxn], sz[maxn];

int find(int v){
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);

    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);

    par[b] = a;
    sz[a] += sz[b];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);

    int n; cin >> n;
    vector<Edge> e;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];

        par[i] = i;
        sz[i] = 1;
        for (int j = 1; j < i; ++j){
            e.push_back({i, j, a[j] ^ a[i]});
        }
    }

    sort(e.begin(), e.end(), [](const Edge &aa, const Edge &bb){
        return aa.w > bb.w;
    });

    int cost = 0;
    int cow = 0;

    for (int i = 0; i < e.size(); ++i){
        if (cow == n) break;

        if (find(e[i].x) != find(e[i].y)){
            cow++;
            cost += e[i].w;
            join(e[i].x, e[i].y);
        }
    }

    cout << cost; 
    return 0;
}