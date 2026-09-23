#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

int n, m, aa, bb, cc, dd;

struct Edge {
    int v, d;

    Edge (int v, int d): v(v), d(d) {};
};

vector<Edge> adj[maxn];
int in[maxn], onpath[maxn];
bool vst[maxn];
int dists[maxn], distt[maxn], distu[maxn], distv[maxn];

struct Node {
    int u, du;

    Node (int u, int du): u(u), du(du) {};

    bool operator<(const Node &other) const {
        return du > other.du;
    }
};

void dijkstra(int *dist, int st){
    dist[st] = 0;

    priority_queue<Node> pq;
    pq.push({st, 0});

    while (!pq.empty()){
        int u = pq.top().u, du = pq.top().du;
        pq.pop();

        if (du > dist[u]) continue;

        for (const Edge &e : adj[u]){
            int v = e.v, d = e.d;

            if (dist[v] > dist[u] + d){
                dist[v] = dist[u] + d;
                pq.push({v, dist[v]});
            }
        }
    }
}

int dp[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    cin >> n >> m >> aa >> bb >> cc >> dd;

    for (int i = 1; i <= m; ++i){
        int x, y, d; cin >> x >> y >> d;

        adj[x].push_back({y, d});
        adj[y].push_back({x, d});
    }   

    for (int i = 0; i < maxn; ++i){
        dists[i] = distt[i] = distu[i] = distv[i] = 1e18;
    }
    dijkstra(dists, aa);
    dijkstra(distt, bb);
    dijkstra(distu, cc);
    dijkstra(distv, dd);

    queue<int> q;

    memset(dp, 0x3f, sizeof(dp));
    memset(in, 0, sizeof(in));
    int minn = distu[dd];

    for (int x = 1; x <= n; ++x) {
        for (auto &e : adj[x]) {
            int y = e.v, d = e.d;
            if (dists[x] + d + distt[y] == dists[bb]) {
                in[y]++;
            }
        }
    }

    for (int i = 1; i <= n; ++i){
        if (in[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()){
        int x = q.front();
        q.pop();
        topo.push_back(x);

        for (const Edge &e : adj[x]){
            int y = e.v, d = e.d;
            if (dists[x] + d + distt[y] != dists[bb]) continue;

            in[y]--;
            if (in[y] == 0) q.push(y);
        }
    }

    memset(vst, false, sizeof(vst));
    for (const int x : topo){
        dp[x] = min(dp[x], distu[x]);
        minn = min(minn, dp[x] + distv[x]);
        vst[x] = 1;

        for (const Edge &e : adj[x]){
            int y = e.v, d = e.d;
            if (dists[x] + d + distt[y] != dists[bb] || vst[y]) continue;

            dp[y] = min(dp[y], dp[x]);
            q.push(y);
        }
    }

    memset(dp, 0x3f, sizeof(dp));
    memset(vst, false, sizeof(vst));
    
    for (const int x : topo){
        dp[x] = min(dp[x], distv[x]);
        minn = min(minn, dp[x] + distu[x]);
        vst[x] = 1;

        for (const Edge &e : adj[x]){
            int y = e.v, d = e.d;
            if (dists[x] + d + distt[y] != dists[bb] || vst[y]) continue;

            dp[y] = min(dp[y], dp[x]);
            q.push(y);
        }
    }

    cout << minn;
    return 0;
}