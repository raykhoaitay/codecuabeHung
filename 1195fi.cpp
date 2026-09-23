#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

struct Edge {
    int u, d;

    Edge(int u, int d): u(u), d(d){};
};

vector<Edge> adj[maxn];

struct Node {
    int u, du, st;

    Node (int u, int du, int st){
        this->u = u;
        this->du = du;
        this->st = st;
    };

    bool operator<(const Node &other) const {
        return du > other.du;
    }
};
int dist[maxn], distc[maxn];

void dijkstra(int start){
    priority_queue<Node> pq;
    memset(dist, 0x3f, sizeof(dist));
    memset(distc, 0x3f, sizeof(distc));

    dist[start] = distc[start] = 0;
    pq.push({start, 0, 0});
    while (!pq.empty()){
        int u = pq.top().u, du = pq.top().du, st = pq.top().st;
        pq.pop();
        if (st == 0 && dist[u] < du) continue;
        if (st == 1 && distc[u] < du) continue;

        for (auto [v, d] : adj[u]){
            if (st == 0){
                if (dist[u] + d < dist[v]) pq.push({v, dist[u] + d, 0});
                dist[v] = min(dist[v], dist[u] + d);

                int minn = dist[u] + d/2;
                if (minn < distc[v]){
                    distc[v] = minn;
                    pq.push({v, distc[v], 1});
                }
            }
            else {
                int minn = min(distc[u] + d, distc[v]);
                if (minn < distc[v]){
                    distc[v] = minn;
                    pq.push({v, distc[v], 1});
                }
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
        int x, y, d; cin >> x >> y >> d;

        adj[x].push_back({y, d});
    }

    dijkstra(1);

    cout << min(dist[n], distc[n]);

    return 0;
}