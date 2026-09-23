#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
const int inf = 1e16;
struct Edge {
    int v, d;
};

vector<Edge> adj[maxn];
int dist[maxn], p[maxn], a[maxn], dsc[maxn];

struct Node {
    int u, du;

    Node (int u, int du): u(u), du(du) {};

    bool operator< (const Node &other) const {
        return du > other.du;
    }
};

void dijkstra(int st){
    for (int i = 0; i < maxn; ++i){
        dist[i] = inf;
        p[i] = inf;
    }

    priority_queue<Node> pq;

    pq.push({st, 0});
    dist[st] = 0;

    while (!pq.empty()){
        Node f = pq.top();
        pq.pop();

        int u = f.u, du = f.du;

        if (du > dist[u]) continue;
        for (const Edge &e : adj[u]){
            int v = e.v, d = e.d;

            if (dist[v] > dist[u] + d){
                dist[v] = dist[u] + d;
                p[v] = u;

                pq.push({v, dist[v]});
            }
            else if (dist[v] == dist[u] + d){
                p[v] = min(p[v], u);
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
    
    int n, m, t; cin >> n >> m >> t;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= m; ++i){
        int x, y, d; cin >> x >> y >> d;

        adj[x].push_back({y, d});
        adj[y].push_back({x, d});
    }

    dijkstra(1);    

    int sum = 0;
    for (int i = 2; i <= n; ++i){
        int curr = i;
        int cow = a[i];
        sum += a[i] * dist[i];

        while (curr != 1){
            if (dist[curr] >= t){
                dsc[curr] += (dist[curr] * cow) - (t * cow);
            }

            curr = p[curr];
        }
    }

    int maxx = 0;
    for (int i = 1; i <= n; ++i){
        maxx = max(maxx, dsc[i]);
    }

    cout << maxx;
    return 0;
}