#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 3e5+10;
vector<vector<int>> adj, radj;
int dp[maxn][30], in[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, m; cin >> n >> m;
    string s; cin >> s;
    adj.assign(n+1, vector<int> ());
    radj.assign(n+1, vector<int> ());
    memset(dp, 0, sizeof(dp));
    memset(in, 0, sizeof(in));

    for (int i = 0; i < m; ++i){
        int x, y; cin >> x >> y;    
        in[y]++;

        adj[x].push_back(y);
        radj[y].push_back(x);
    }

    vector<int> topo;
    queue<int> q;

    for (int i = 1; i <= n; ++i){
        if (in[i] == 0) q.push(i);
    }

    while (!q.empty()){
        int x = q.front();
        q.pop();

        topo.push_back(x);

        for (const int &v : adj[x]){
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }

    if (topo.size() < n){
        cout << -1 << '\n';
        return 0;
    }

    int ans = -1e9;
    for (int i = 0; i < n; ++i){
        int maxx = 0;
        int idx = topo[i];
        for (const int &v : radj[idx]){
            for (int j = 0; j < 26; ++j){
                dp[idx][j] = max(dp[idx][j], dp[v][j]);
            }
        }

        dp[idx][s[idx-1] - 'a']++;
        ans = max(ans, dp[idx][s[idx-1] - 'a']);
    }

    cout << ans;

    return 0;
}