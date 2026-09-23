#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
const int maxk = 55;
const int inf = 1e18;

int a[maxn];
bool cn[maxk][maxk];

struct Edge {
    int v, d;

    Edge (int v, int d): v(v), d(d) {};
};

vector<Edge> adj[maxn];
vector<int> pos[maxk];
int p[maxn];

struct Node {
    int u, du;

    Node (int u, int du): u(u), du(du) {};

    bool operator< (const Node &other) const {
        return du > other.du;
    }
};

int dist[maxn];

void dijkstra(){
    for (int i = 1; i < maxn; ++i) dist[i] = inf;
    dist[1] = 0;
    p[1] = 1;

    priority_queue<Node> pq;
    pq.push({1, 0});

    while (!pq.empty()){
        Node f = pq.top();
        pq.pop();

        int u = f.u, du = f.du;
        if (du > dist[u]) continue;

        for (const Edge &e : adj[u]){
            int v = e.v, d = e.d;

            if (dist[v] > dist[u] + d){
                dist[v] = dist[u] + d;
                p[v]= u;
                pq.push({v, dist[v]});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];

        pos[a[i]].push_back(i);
    }

    for (int i = 1; i <= k; ++i){
        for (int j = 1; j <= k; ++j){
            char c; cin >> c;
            cn[i][j] = (c - '0') ? 1 : 0;
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= k; ++j){
            if (cn[a[i]][j]){
                int c1 = 0;
                int f = lower_bound(pos[j].begin(), pos[j].end(), i) - pos[j].begin() - 1;
                if (f < 0 || f >= pos[j].size()) c1 = 1;
                if (!c1 && pos[j][f] >= i) c1 = 1;

                if (!c1) adj[i].push_back({pos[j][f], i - pos[j][f]});

                f = upper_bound(pos[j].begin(), pos[j].end(), i) - pos[j].begin();
                if (f < 0 || f >= pos[j].size()) continue;
                if (pos[j][f] <= i) continue;

                adj[i].push_back({pos[j][f], pos[j][f] - i});
            }
        }
    }

    dijkstra();

    if (dist[n] == inf){
        int minn = inf;

        for (int i : pos[a[n]]){
            minn = min(minn, dist[i] - (abs(i - p[i])) + (abs(p[i] - n)));
        }

        if (minn == inf) cout << -1;
        else cout << minn;
    }
    else cout << dist[n];

    return 0;
}