#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+1000;
int isLeaf[maxn], h[maxn], isP[maxn];

struct Exit {
    int node, height;

    Exit (){};
    Exit (int node, int height): node(node), height(height) {};
};

vector<vector<int>> adj(maxn);

bool bfs(int node, int height){
    queue<int> q;
    memset(h, -1, sizeof(h));

    h[node] = 0;
    q.push(node);

    while (!q.empty()){
        int x = q.front();
        q.pop();

        for (const int &v : adj[x]){
            if (h[v] != -1) continue;
            h[v] = h[x] + 1;
            if (h[v] > height) continue;
            if (isLeaf[v] == 1 && isP[v] == 1) return true;
            isP[v] = 1;
            q.push(v);
        }
    }

    isP[node] = 1;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
    int n, k; cin >> n >> k;
    for (int i = 1; i < n; ++i){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<Exit> leaf;
    queue<int> q;
    q.push(k);

    memset(isLeaf, 0, sizeof(isLeaf));
    memset(h, -1, sizeof(h));
    h[k] = 0;

    while (!q.empty()){
        int x = q.front();
        q.pop();

        int trg = 0;
        for (const int &v : adj[x]){
            if (h[v] != -1) continue;
            h[v] = h[x] + 1;
            q.push(v);
            trg++;
        }

        if (trg == 0){
            leaf.emplace_back(x, h[x]);
            isLeaf[x] = 1;
        }
    }

    sort(leaf.begin(), leaf.end(), [](const Exit &aa, const Exit &bb){
        return aa.height < bb.height;
    });

    int cow = 0;
    memset(isP, 0, sizeof(isP));
    for (int i = 0; i < leaf.size(); ++i){
        if (bfs(leaf[i].node, leaf[i].height) == false) cow++;
    }

    cout << cow; 

    return 0;
}