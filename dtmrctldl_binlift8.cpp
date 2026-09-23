#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
const int lg = 30;

int up[maxn][lg], thn[maxn][lg], rev[maxn][lg];
int a[maxn];
bool vst[maxn];

void dfs(int u, int par){
    up[u][0] = par;
    thn[u][0] = a[par];
    rev[u][0] = a[par];
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
            int mid = up[u][j-1];

            up[u][j] = up[mid][j-1];
            thn[u][j] = thn[u][j-1] *
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, q; cin >> n >> mod >> q;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}