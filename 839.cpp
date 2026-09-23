#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1000*250+10;

struct Cow {
    int w, t; 

    Cow (){};
    Cow (int w, int t): w(w), t(t) {};
};

vector<Cow> a(260);
bool dp[maxn];
vector<int> ww(maxn);

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    int n, w; cin >> n >> w;

    int sz = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].w >> a[i].t;
        sz += a[i].t;
    }

    int maxx = -1;
    memset(dp, 0, sizeof(dp));
    ww.assign(maxn, INT_MAX);
    dp[0] = 1;
    ww[0] = 0;

    for (int i = 1; i <= n; ++i){
        for (int j = sz; j+1; --j){
            if (dp[j]){
                dp[j + a[i].t] = 1;
                
                if (ww[j + a[i].t] == INT_MAX) ww[j + a[i].t] = ww[j] + a[i].w;
                else if (ww[j + a[i].t] < w) ww[j + a[i].t] = max(ww[j + a[i].t], ww[j] + a[i].w);
                else {
                    if (ww[j] + a[i].w < ww[j + a[i].t] && ww[j] + a[i].w >= w) ww[j + a[i].t] = ww[j] + a[i].w;
                }

                if (ww[j + a[i].t] >= w && ww[j + a[i].t] != INT_MAX){
                    maxx = max(maxx, (j + a[i].t) * 1000 / ww[j + a[i].t]);
                }
            }
        }
    }

    cout << maxx;
    return 0;
}