#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
const int LOG = 20;

vector<int> adj[maxn];
int up[maxn][LOG], depth[maxn];
bool vst[maxn];
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
    for (int j = 1; j < LOG; ++j){
        for (int u = 1; u <= n; ++u){
            up[u][j] = up[up[u][j-1]][j-1];
        }
    }
}

int jump(int u, int k){
    for (int j = LOG; j+1; --j){
        if (k & (1 << j)){
            u = up[u][j];
        }
    }

    return u;
}

int lca(int u, int v){
    if (depth[v] > depth[u]) swap(u, v);

    v = jump(v, depth[u] - depth[v]);

    if (u == v) return u;

    for (int j = LOG; j+1; --j){
        if (up[u][j] != up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif
    cin >> n >> q;
    
    for (int i = 2; i <= n; ++i){
        int j; cin >> j;
        if (i == j) continue;

        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    memset(up, 0, sizeof(up));
    dfs(1, 0);
    init();

    while (q--){
        int x, k; cin >> x >> k;
        int res = jump(x, k);
        if (res) cout << res << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}