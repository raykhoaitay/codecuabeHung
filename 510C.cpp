#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 105;
string s[maxn];
int in[maxn];
vector<vector<int>> adj(maxn);

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];

    memset(in, 0, sizeof(in));
    for (int i = 1; i < n; ++i){
        int c = 1;
        for (int j = 0; j < min(s[i].size(), s[i+1].size()); ++j){
            if (s[i][j] != s[i+1][j]){
                adj[s[i][j] - 'a'].push_back(s[i+1][j] - 'a'); 
                in[s[i+1][j] - 'a']++;
                c = 0;
                break;
            }
        }

        if (c && s[i].size() > s[i+1].size()){
            cout << "Impossible\n";
            return 0;
        }
    }

    vector<int> topo;
    queue<int> q;

    for (int i = 0; i < 26; ++i){
        if (in[i] == 0) q.push(i);
    }

    while (!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (const int &v : adj[u]){
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }

    if (topo.size() < 26){
        cout << "Impossible\n";
        return 0;
    } else {
        for (const int v : topo) cout << (char)(v + 'a');
    }
    return 0;
}