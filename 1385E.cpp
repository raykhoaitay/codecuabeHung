#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
int in[maxn], out[maxn], idx[maxn];

struct Edge {
    int x, y;

    Edge (){};
    Edge (int x, int y): x(x), y(y) {};
};

void solver(){
    int n, m; cin >> n >> m;

    int t, x, y;
    vector<Edge> pending, original;
    vector<vector<int>> wadj(n+1);
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));

    for (int i = 1; i <= m; ++i){
        cin >> t >> x >> y;
        if (t == 0){
            pending.emplace_back(x, y);
        }
        else {
            in[y]++;
            out[x]++;
            wadj[x].push_back(y);
            original.emplace_back(x, y);
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i){
        if (in[i] == 0 && out[i] > 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()){
        int x = q.front();
        q.pop();
        topo.push_back(x);

        for (int &v : wadj[x]){
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }

    for (int i = 1; i <= n; ++i){
        if (in[i] > 0){
            cout << "NO\n";
            return;
        }
        else {
            if (out[i] == 0) topo.push_back(i);
        }
    }

    cout << "YES\n";
    for (int i = 0; i < topo.size(); ++i){
        idx[topo[i]] = i;
    }

    for (const auto &edge : pending){
        int x = edge.x, y = edge.y;
        if (idx[x] > idx[y]) swap(x, y);

        cout << x << ' ' << y << '\n';
    }

    for (const auto &edge : original) cout << edge.x << ' ' << edge.y << '\n';
    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--) solver();

    return 0;
}