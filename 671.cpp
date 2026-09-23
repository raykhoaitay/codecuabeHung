#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

struct Point {
    int x, y, idx;

    Point (){};
    Point (int x, int y, int idx): x(x), y(y), idx(idx) {};
};

struct Node {
    int idx, to, cost;

    Node (){};
    Node (int idx, int to, int cost): idx(idx), to(to), cost(cost) {};

    bool operator <(const Node &other) const {
        return cost > other.cost;
    }
};

vector<Point> a;
vector<vector<int>> adj(maxn);
priority_queue<Node> q;
int visited[maxn];

void right(int u, int cost){
    for (int i = 0; i < adj[u].size(); ++i){
        int idx = adj[u][i];
        if (visited[idx]) continue;
        if (a[idx].x == a[u].x && a[idx].y > a[u].y){
            q.push({idx, 1, cost});
        }
        else if (a[idx].x < a[u].x){
            q.push({idx, 3, cost+1});
        }
        else if (a[idx].x > a[u].x){
            q.push({idx, 4, cost+1});
        }
        visited[idx] = 1;
    }
}

void left(int u, int cost){
    for (int i = 0; i < adj[u].size(); ++i){
        int idx = adj[u][i];
        if (visited[idx]) continue;
        if (a[idx].x == a[u].x && a[idx].y < a[u].y){
            q.push({idx, 2, cost});
        }
        else if (a[idx].x < a[u].x){
            q.push({idx, 3, cost+1});
        }
        else if (a[idx].x > a[u].x){
            q.push({idx, 4, cost+1});
        }
        visited[idx] = 1;
    }
}

void down(int u, int cost){
    for (int i = 0; i < adj[u].size(); ++i){
        int idx = adj[u][i];
        if (visited[idx]) continue;
        if (a[idx].y == a[u].y && a[idx].x < a[u].x){
            q.push({idx, 3, cost});
        }
        else if (a[idx].y < a[u].y){
            q.push({idx, 2, cost+1});
        }
        else if (a[idx].y > a[u].y){
            q.push({idx, 1, cost+1});
        }
        visited[idx] = 1;
    }
}

void up(int u, int cost){
    for (int i = 0; i < adj[u].size(); ++i){
        int idx = adj[u][i];
        if (visited[idx]) continue;
        if (a[idx].y == a[u].y && a[idx].x > a[u].x){
            q.push({idx, 4, cost});
        }
        else if (a[idx].y < a[u].y){
            q.push({idx, 2, cost+1});
        }
        else if (a[idx].y > a[u].y){
            q.push({idx, 1, cost+1});
        }
        visited[idx] = 1;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    int n, sx, sy, ex, ey; cin >> n >> sx >> sy >> ex >> ey;

    for (int i = 0; i < n; ++i){
        int x, y; cin >> x >> y;
        a.emplace_back(x, y, i);
    }

    a.emplace_back(sx, sy, n);
    a.emplace_back(ex, ey, n+1);

    sort(a.begin(), a.end(), [](const Point &aa, const Point &bb){
        if (aa.x == bb.x) return aa.y < bb.y; 
        return aa.x < bb.x;
    });

    for (int i = 0; i <= n; ++i){
        if (a[i].x == a[i+1].x){
            adj[a[i].idx].push_back(a[i+1].idx);
            adj[a[i+1].idx].push_back(a[i].idx);
        }
    }

    sort(a.begin(), a.end(), [](const Point &aa, const Point &bb){
        if (aa.y == bb.y) return aa.x < bb.x;
        return aa.y < bb.y;
    });

    for (int i = 0; i <= n; ++i){
        if (a[i].y == a[i+1].y){
            adj[a[i].idx].push_back(a[i+1].idx);
            adj[a[i+1].idx].push_back(a[i].idx);
        }
    }

    sort(a.begin(), a.end(), [](const Point &aa, const Point &bb){
        return aa.idx < bb.idx;
    });

    int u = n;
    memset(visited, 0, sizeof(visited));
    visited[u] = 1;
    for (int i = 0; i < adj[u].size(); ++i){
        int idx = adj[u][i];
        if (visited[idx]) continue;
        if (a[idx].x == a[u].x && a[idx].y > a[u].y){
            q.push({idx, 1, 0});
        }
        else if (a[idx].y < a[u].y){
            q.push({idx, 2, 0});
        }
        else if (a[idx].x < a[u].x){
            q.push({idx, 3, 0});
        }
        else if (a[idx].x > a[u].x){
            q.push({idx, 4, 0});
        }
    }

    int ans = -1;
    while (!q.empty()){
        Node f = q.top();
        q.pop();

        if (f.idx == n+1){
            ans = f.cost;
            break;
        }

        if (f.to == 1){
            right(f.idx, f.cost);
        }
        else if (f.to == 2){
            left(f.idx, f.cost);
        }
        else if (f.to == 3){
            down(f.idx, f.cost);
        }
        else if (f.to == 4){
            up(f.idx, f.cost);
        }
    }

    cout << ans;

    return 0;
}