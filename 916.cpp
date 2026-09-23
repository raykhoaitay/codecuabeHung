// #include <bits/stdc++.h>

// #define int long long
// using namespace std;

// void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
// void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

// int mod = 1000000007;
// const int maxn = 120;
// vector<vector<int>> adj(maxn, vector<int> ());
// int cl[5];
// int color[maxn];

// int check(int u){
//     memset(cl, 0, sizeof(cl));

//     int c = 0;
//     for (int v : adj[u]){
//         if (v > u) break;

//         cl[color[v]]++;
//         if (color[v] != color[u]){
//             continue;
//         }

//         c = 1;
//     }

//     if (c == 1){
//         for (int i = 1; i <= 4; ++i){
//             if (cl[i] == 0) return i;
//         }
//     }

//     return -1;
// }

// void bfs(){
//     queue<int> q;
//     color[1] = 1;
//     q.push(1);

//     while (!q.empty()){
//         int u = q.front();
//         q.pop();

//         int d = check(u);
//         if (d != -1) color[u] = d;

//         int change = (color[u] == 1) ? 2 : 1;
//         for (int v : adj[u]){
//             if (color[v]) continue;

//             color[v] = change;
//             q.push(v);
//         }
//     }
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     #ifndef ONLINE_JUDGE
//         ray();
//     #endif

//     int n, m; cin >> n >> m;
//     int x, y;
//     for (int i = 0; i < m; ++i){
//         cin >> x >> y;

//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }

//     memset(color, 0, sizeof(color));
//     for (int i = 0; i < maxn; ++i){
//         if (adj[i].size() != 0){
//             sort(adj[i].begin(), adj[i].end());
//         }
//     }

//     bfs();
//     for (int i = 1; i <= n; ++i){
//         cout << color[i];
//     }

//     cout << '\n';
//     return 0;
// }


#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 120;
vector<vector<int>> adj(maxn, vector<int> ());
int color[maxn], cl[5];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m; cin >> n >> m;
    int x, y;

    for (int i = 0; i < m; ++i){
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(color, 0, sizeof(color));
    for (int i = 1; i <= n; ++i){
        memset(cl, 0, sizeof(cl));
        for (int v : adj[i]){
            cl[color[v]]++;
        }

        for (int j = 1; j <= 4; ++j){
            if (cl[j] == 0){
                color[i] = j;
                break;
            }
        }
    }

    for (int i = 1; i <= n; ++i){
        cout << color[i];
    }
    return 0;
}