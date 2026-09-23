#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
const int lg = 30;

vector<int> adj[maxn];
int n, q;
int depth[maxn], up[maxn][lg];
bool vst[maxn];

void dfs(int u, int par){
    up[u][0] = par;
    vst[u] = 1;

    for (const int &v : adj[u]){
        if (vst[v] == 1) continue;

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
    if (depth[v] < depth[u]){
        swap(u, v);
    }

    v = jump(v, depth[v] - depth[u]);
    if (v == u) return u;

    for (int j = lg-1; j+1; --j){
        if (up[u][j] != up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}

int solver(){
    int a, b, root;
    cin >> a >> b >> root;

    int x = lca(a, root), 
    y = lca(b, root),
    z = lca(a, b);

    int maxx = max(max(depth[x], depth[y]), depth[z]);
    if (depth[x] == maxx) return x;
    if (depth[y] == maxx) return y;
    if (depth[z] == maxx) return z;
}

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

    while (q--) cout << solver() << '\n';
    return 0;
}