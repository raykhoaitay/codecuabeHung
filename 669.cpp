#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1010;

struct Point {
    int x, y, idx;

    Point (){};
};

struct Edge {
    int u, v, w;

    Edge (){};
    Edge (int u, int v, int w): u(u), v(v), w(w) {};
};

int dist(const Point &x, const Point &y){
    return (x.x - y.x)*(x.x-y.x) + (x.y - y.y)*(x.y-y.y);
}

int par[maxn], sz[maxn];
vector<Point> a(maxn);

int find(int v){
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}

void joint(int a, int b){
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

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n; cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].x >> a[i].y;
        a[i].idx = i;
        par[i] = i;
        sz[i] = 1;
    }

    vector<Edge> edges;
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            edges.emplace_back(i, j, dist(a[i], a[j]));
        }
    }

    sort(edges.begin(), edges.end(), [](const auto &x, const auto &y){
        return x.w < y.w;
    });

    int cow = 0, maxx = -1e9;
    for (int i = 0; i < edges.size(); ++i){
        
        if (find(edges[i].u) != find(edges[i].v)){
            joint(edges[i].u, edges[i].v);
            maxx = max(maxx, edges[i].w);
            cow++;
            if (cow == n-1) break;
        }
    }

    cout << maxx << '\n';

    return 0;
}