#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

int a[maxn], ok[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, k; cin >> n >> k;
    a[0] = 0;
    memset(ok, 0, sizeof(ok));

    for (int i = 1; i <= n; ++i){
        cin >> a[i];

        if (a[i] - a[i-1] <= k) ok[i] = ok[i-1] + 1;
    }

    vector<int> dp;
    for (int i = n; i+1; --i){
        auto it = upper_bound(dp.begin(), dp.end(), ok[i]);
        if (it == dp.end()) dp.push_back(ok[i]);
        else *it = ok[i];
    }

    cout << dp.size() - 1;

    return 0;
}