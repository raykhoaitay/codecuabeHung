#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
int par[maxn], sz[maxn], stt[maxn];
vector<int> adj[maxn];

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

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        par[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; ++i){
        int x, y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    } 

    vector<int> qr(n+1, 0);
    for (int i = 1; i <= n; ++i){
        cin >> qr[i];
    }

    stack<int> rs;
    memset(stt, 0, sizeof(stt));
    int cow = 0;
    for (int i = n; i > 0; --i){
        stt[qr[i]] = 1;
        cow++;

        for (int v : adj[qr[i]]){
            if (stt[v] == 1) joint(qr[i], v);
        }

        if (sz[find(qr[i])] == cow) rs.push(1);
        else rs.push(0);
    }

    while (!rs.empty()){
        if (rs.top() == 1) cout << "YES\n";
        else cout << "NO\n";

        rs.pop();
    }

    return 0;
}