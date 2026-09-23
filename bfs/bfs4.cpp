#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

int vis[100005];

int solver(){
    int n, m; cin >> n >> m;

    queue<int> q;
    memset(vis, -1, sizeof(vis));
    q.push(m);
    vis[m] = 0;

    while (!q.empty()){
        int f = q.front();
        q.pop();

        if (f == n) break;

        if (f % 2){
            if (vis[f+1] == -1){
                q.push(f+1);
                vis[f+1] = vis[f] + 1;
            }
        }
        else {
            if (vis[f+1] == -1){
                q.push(f+1);
                vis[f+1] = vis[f] + 1;
            }
            if (vis[f/2] == -1){
                q.push(f/2);
                vis[f/2] = vis[f] + 1;
            }
        }
    }

    return vis[n];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--) cout << solver() << '\n';

    return 0;
}