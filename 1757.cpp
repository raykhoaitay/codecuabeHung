#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
int in[maxn];
vector<vector<int>> adj(maxn);

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, m; cin >> n >> m;

    memset(in, 0, sizeof(in));    for (int i = 0; i < m; ++i){
        int x, y; cin >> y >> x;

        adj[x].push_back(y);
        in[y]++;
    }

    vector<int> topo;
    priority_queue<int> q;

    for (int i = 1; i <= n; ++i){
        if (in[i] == 0) q.push(i);
    }

    while (!q.empty()){
        int x = q.top();
        q.pop();
        topo.push_back(x);
        for (const int &v : adj[x]){
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }

    reverse(topo.begin(), topo.end());
    for (const int &v : topo) cout << v << ' ';
    return 0;
}