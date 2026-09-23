#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

int n, m, k;
struct Edge {
    int v, d;
};

struct Grass {
    int x, yum;
} gr[maxn];

vector<Edge> adj[maxn];
int dist[maxn], disth[maxn];

struct Node {
    int u, du;

    Node (int u, int du): u(u), du(du) {};

    bool operator<(const Node &other) const {
        return du > other.du;
    }
};

void dijkstra1(int st){
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<Node> pq;

    dist[st] = 0;
    pq.push({st, 0});

    while (!pq.empty()){
        Node f = pq.top();
        pq.pop();

        int u = f.u, du = f.du;
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

void dijkstra2(){
    memset(disth, 0x3f, sizeof(disth)); 
    priority_queue<Node> pq;

    for (int i = 1; i <= k; ++i){
        disth[gr[i].x] = dist[gr[i].x] - gr[i].yum;
        pq.push({gr[i].x, disth[gr[i].x]});
    }

    while (!pq.empty()){
        Node f = pq.top();
        pq.pop();

        int u = f.u, du = f.du;

        if (du > disth[u]) continue;

        for (const Edge &e : adj[u]){
            int v = e.v, d = e.d;

            if (disth[v] > disth[u] + d){
                disth[v] = disth[u] + d;
                pq.push({v, disth[v]});
            }
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i){
        int x, y, d; cin >> x >> y >> d;

        adj[x].push_back({y, d});
        adj[y].push_back({x, d});
    }

    for (int i = 1; i <= k; ++i){
        cin >> gr[i].x >> gr[i].yum;
    }

    dijkstra1(n);
    dijkstra2();

    for (int i = 1; i < n; ++i){
        if (disth[i] <= dist[i]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}