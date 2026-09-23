#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

vector<vector<int>> wi(2010);

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s; cin >> s >> n;
    int v, w, k;
    for (int i = 1; i <= n; ++i){
        cin >> v >> w >> k;

        for (int _ = 0; _ < min(k, s/w); ++_){
            wi[w].push_back(v);
        }
    }

    vector<int> ww, vv;

    for (int i = 0; i < 2010; ++i){
        if (wi[i].size() == 0) continue;

        sort(wi[i].begin(), wi[i].end(), [](const int &x, const int &y){
            return x > y;
        });

        int hihi = wi[i].size();
        for (int j = 0; j < min(hihi, s/i); ++j){
            ww.push_back(i);
            vv.push_back(wi[i][j]);
        }
    }
    
    int sz = ww.size();
    int dp[s+10];

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < sz; ++i){
        for (int j = s; j >= ww[i]; --j){
            dp[j] = max(dp[j], dp[j - ww[i]] + vv[i]);
        }
    }

    cout << dp[s];

    return 0;
}