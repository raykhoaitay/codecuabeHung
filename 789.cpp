#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

struct Edge {
    int u, v, w;

    Edge (){};
};

struct xamL {
    int k, v, idx, val;

    xamL (){
        val = 0;
    };
};

vector<Edge> a;
vector<xamL> q;
int par[maxn], sz[maxn];

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

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    int n, m; cin >> n >> m;
    a.assign(n, Edge());
    q.assign(m+1, xamL());

    for (int i = 1; i <= n; ++i){
        par[i] = i;
        sz[i] = 1;
    }

    for (int i = 1; i < n; ++i){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }

    for (int i = 1; i <= m; ++i){
        cin >> q[i].k >> q[i].v;
        q[i].idx = i;
    }

    sort(a.begin()+1, a.end(), [](const auto &x, const auto &y){
        return x.w > y.w;
    });

    sort(q.begin()+1, q.end(), [](const auto &x, const auto &y){
        return x.k > y.k;
    });

    int i = 1, j = 1;
    while (j <= m){
        while (i < n && a[i].w >= q[j].k){
            joint(a[i].u, a[i].v);
            i++;
        }

        q[j].val = sz[find(q[j].v)] - 1;
        j++;
    }

    sort(q.begin()+1, q.end(), [](const auto &x, const auto &y){
        return x.idx < y.idx;
    });

    for (int i = 1; i <= m; ++i) cout << q[i].val << '\n';

    return 0;
}