#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1010;

int a[maxn], b[maxn];
int dp[maxn][maxn];

int n;
bool check(int i, int j){
    return (1 <= i and i <= n) and (1 <= j and j <= n);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (abs(a[i] - b[j]) <= 4){
                dp[i][j] = dp[i-1][j-1] + 1;
            }

            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
    }

    cout << dp[n][n];
    return 0;
}