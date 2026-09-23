#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {
    string inp = name + ".inp"; 
    string out = name + ".out"; 
    freopen(inp.c_str(), "r", stdin); 
    freopen(out.c_str(), "w", stdout);
}
void ray() {
    freopen("i.inp", "r", stdin); 
    freopen("o.out", "w", stdout);
}

const int mod = 1000000007;
const int maxn = 1e5 + 10;
const int INF = 1e18;

struct Edge {
    int v, d;
};

vector<Edge> adj[maxn];
int dist[maxn], maxx[maxn], minn[maxn], cow[maxn];

struct Node {
    int u, du;
    bool operator<(const Node &other) const {
        return du > other.du;
    }
};

void dijkstra(int start) {
    priority_queue<Node> pq;

    for (int i = 1; i < maxn; ++i) {
        dist[i] = INF;
        minn[i] = INF;
        maxx[i] = -1;
        cow[i] = 0;
    }

    dist[start] = 0;
    minn[start] = 0;
    maxx[start] = 0;
    cow[start] = 1;

    pq.push({start, 0});

    while (!pq.empty()) {
        Node f = pq.top();
        pq.pop();
        
        int u = f.u, du = f.du;
        if (du > dist[u]) continue;

        for (const Edge &e : adj[u]) {
            int v = e.v, d = e.d;

            if (dist[v] > dist[u] + d) {
                dist[v] = dist[u] + d;
                cow[v] = cow[u];
                minn[v] = minn[u] + 1;
                maxx[v] = maxx[u] + 1;
                pq.push({v, dist[v]});
            } 
            else if (dist[v] == dist[u] + d) {
                cow[v] = (cow[v] + cow[u]) % mod;
                minn[v] = min(minn[v], minn[u] + 1);
                maxx[v] = max(maxx[v], maxx[u] + 1);
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
    for (int i = 0; i < m; ++i){
        int x, y, d; cin >> x >> y >> d;
        adj[x].push_back({y, d});
    }

    dijkstra(1);
    cout << dist[n] << ' ' << cow[n] << ' ' << minn[n] << ' ' << maxx[n] << '\n';
    return 0;
}