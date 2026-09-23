#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
const int lg = 30;

bool vst[maxn];
int depth[maxn], up[maxn][lg];
vector<int> adj[maxn];
int n, q; 

void dfs(int u, int par){
    up[u][0] = par;
    vst[u] = 1;

    for (const int v : adj[u]){
        if (vst[v]) continue;

        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

void init(){
    for (int j = 1; j < lg; ++j){
        for (int u = 1; u <= n; ++u){
            up[u][j] = up[up[u][j-1]][j-1];
        }
    }
}

int jump(int u, int k){
    for (int j = lg-1; j+1; j--){
        if (k & (1 << j)){
            u = up[u][j];
        }
    }

    return u;
}

int lca(int u, int v){
    if (depth[v] < depth[u]) swap(u, v);

    v = jump(v, depth[v] - depth[u]);
    if (v == u) return u;

    for (int j = lg-1; j+1; --j){
        if (up[u][j] == up[v][j]) continue;

        u = up[u][j];
        v = up[v][j];
    }

    return up[u][0];
}

struct SegmentTree {
    int t[maxn*4];

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v] = tl;
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        t[v] = lca(t[2*v], t[2*v+1]);
    }

    int query(int v, int tl, int tr, int l, int r){
        if (r < tl || tr < l) return -1;
        if (l <= tl && tr <= r) return t[v];

        int tm = (tl + tr) / 2;
        int s1 = query(2*v, tl, tm, l, r);
        int s2 = query(2*v+1, tm+1, tr, l, r);
        if (s1 == -1 || s2 == -1) return max(s1, s2);

        return lca(s1, s2);
    }
} st;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    cin >> n >> q;
    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(up, 0, sizeof(up));

    dfs(1, 0);
    init();

    st.build(1, 1, n);

    while (q--){
        int l, r; cin >> l >> r;

        cout << st.query(1, 1, n, l, r) << '\n';
    }
    return 0;
}