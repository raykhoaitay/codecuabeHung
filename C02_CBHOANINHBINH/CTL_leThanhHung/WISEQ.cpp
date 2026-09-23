#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 5005;

int a[maxn], ww[maxn][maxn];
bool dp[maxn][maxn];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ray("WISEQ");
    int n, w; cin >> n >> w;
    int maxx = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (a[i] <= w) maxx = 1;
    }

    memset(dp, false, sizeof(dp));
    memset(ww, 0x3f, sizeof(ww));
    ww[0][0] = 0;

    for (int i = 1; i <= n; ++i){   
        dp[i][0] = dp[i][1] = 1;

        ww[i][1] = a[i];
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= i; ++j){
            if (a[i] > a[j]){
                for (int k = 1; k <= j; ++k){
                    if (dp[j][k]){
                        dp[i][k+1] = true;
                        ww[i][k+1] = min(ww[j][k] + a[i], ww[i][k+1]); 

                        if (ww[i][k+1] <= w) maxx = max(maxx, k+1);
                    }
                }
            }
        }
    }

    cout << maxx;
    return 0;
}