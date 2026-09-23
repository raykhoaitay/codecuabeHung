#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
int cow[maxn];
bool visited[maxn];
vector<vector<int>> adj(maxn), rdj(maxn);
vector<int> topo;

void dfs(int u){
    visited[u] = 1;

    for (const int &v : adj[u]){
        if (!visited[v]) dfs(v);
    }

    topo.push_back(u);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, m; cin >> n >> m;
    int x, y;

    for (int i = 1; i <= m; ++i){
        cin >> x >> y;

        adj[x].push_back(y);
        rdj[y].push_back(x);
    }

    dfs(1);
    reverse(topo.begin(), topo.end());
    memset(cow, 0, sizeof(cow));
    cow[1] = 1;

    for (int i = 1; i < topo.size(); ++i){
        for (const int &v : rdj[topo[i]]){
            cow[topo[i]] += cow[v];
            cow[topo[i]] %= mod;
        }
    }

    cout << cow[n];
    return 0;
}