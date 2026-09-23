#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 505;

int a[maxn];
bool dp[maxn][maxn], mk[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    memset(dp, false, sizeof(dp));
    memset(mk, false, sizeof(mk));

    dp[0][0] = 1;
    mk[0] = 1;

    sort(a+1, a+n+1);

    for (int i = 1; i <= n; ++i){
        for (int j = k; j >= 0; --j){
            if (mk[j] && j + a[i] <= k){
                int target = j + a[i];
                for (int l = 0; l <= k; ++l){
                    if (dp[j][l]){
                        dp[target][l] = 1;
                        dp[target][l+a[i]] = 1;
                    }
                }

                dp[target][a[i]] = 1;
                mk[target] = 1;
            }
        }
    }

    vector<int> result;
    for (int i = 0; i <= k; ++i){
        if (dp[k][i]) result.push_back(i);
    }

    cout << result.size() << '\n';

    for (const int &x : result) cout << x << ' ';
    return 0;
}