#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

struct Edge {
    int v, d;
};

vector<Edge> adj[maxn];
int dist[maxn];

struct Node {
    int u, du;

    Node (int u, int du): u(u), du(du) {};

    bool operator<(const Node &other) const {
        return du > other.du;
    }
};

void dijkstra(int st){   
    priority_queue<Node> pq;
    pq.push({st, 0});

    memset(dist, 0x3f, sizeof(dist));
    dist[st] = 0;

    while (!pq.empty()){
        Node f = pq.top();
        int u = f.u, du = f.du;
        pq.pop();

        if (du > dist[u]) continue;
        for (const Edge &g : adj[u]){
            int v = g.v, d = g.d;

            if (du + d < dist[v]){
                dist[v] = du + d;
                pq.push({v, dist[v]});
            }
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
    for (int i = 1; i <= m; ++i){
        int u, v, d; cin >> u >> v >> d;

        adj[u].push_back({v, d});
    }

    dijkstra(1);
    for (int i = 1; i <= n; ++i){
        cout << dist[i] << ' ';
    }

    return 0;
}