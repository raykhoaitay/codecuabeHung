#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
const int lg = 30;

int comp[maxn], up[maxn][lg];
int vst[maxn], in[maxn], depth[maxn], pos[maxn];
int idx = 1;
unordered_map<int, int> len, start;

void dfs(int u){
    for (int v : adj[u]){
        if (vst[v] == 1){
            len[idx] = depth[v] - depth[u] + 1;
            start[idx] = v;
            pos[u] = len[idx] - 1;
            vst[u] = 2;
            return;
        }

        vst[v] = 1;
        comp[v] = idx;

        depth[v] = depth[u] + 1;
        dfs(v, u);
        if (pos[v] >= 1){
            pos[u] = pos[v] - 1;
        }
    }

    vst[u] = 2;
}

void init(){
    for (int j = 1; j < lg; ++j){
        for (int u = 1; u <= n; ++u){
            up[u][j] = up[up[u][j-1]][j-1];
        }
    }
}

int jump(int u, int k){
    for (int j = lg-1; j+1; --j){
        if (k & (1 << j)){
            u = up[u][j];
        }
    }

    return u;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        int j; cin >> j;

        if (i == j) continue;
        in[j]++;
        adj[i].push_back(j);
        up[i][0] = j;
    }

    init();
    memset(pos, -1, sizeof(pos));
    for (int i = 1; i <= n; ++i){
        if (!vst[i] && !in[i]){
            vst[i] = 1;
            comp[i] = idx;
            dfs(i);
            idx++;
        }
    }

    while (q--){
        int u, v; cin >> u >> v;

        if (u == v){
            cout << 0 << '\n';
            continue;
        }

        if (comp[u] != comp[v]){
            cout << -1 << '\n';
            continue;
        }

        if (pos[v] != -1){
            if (pos[u] != -1){
                int ln = len[comp[u]];

                if (pos[u] > pos[v]) cout << ln - pos[u] + pos[v] << '\n';
                else cout << pos[v] - pos[u] << '\n';

                continue;
            }

            cout << depth[start[comp[v]]] - depth[u] + pos[v] - pos[start[comp[v]]] << '\n';
        }

        if (pos[u] != -1){
            cout << -1 << '\n';
            continue;
        }

        
    }

    return 0;
}