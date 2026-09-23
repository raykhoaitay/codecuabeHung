#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2510;
vector<vector<int>> adj(maxn);
int par[maxn], h[maxn], minn = 1e9;

void bfs(int u){
    queue<int> q;
    q.push(u);
    memset(par, 0, sizeof(par));
    memset(h, 0, sizeof(h));
    par[u] = u;
    h[u] = 1;

    while (!q.empty()){
        int x = q.front();
        q.pop();

        for (const int &v : adj[x]){
            if (h[v] != 0){
                if (par[x] != v){
                    minn = min(minn, h[v] + h[x] - 1);
                }
                continue;
            }

            h[v] = h[x] + 1;
            par[v] = x;
            q.push(v);
        }
    }
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
        adj[y].push_back(x);
    } 

    for (int i = 1; i <= n; ++i){
        bfs(i);
    }

    if (minn == 1e9) cout << -1;
    else cout << minn;
    return 0;
}