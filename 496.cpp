#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    // ray();
    int n, t; cin >> n >> t;
    vector<int> x(n), v(n), e(n);

    for (int i = 0; i < n; ++i){
        cin >> x[i] >> v[i];

        e[i] = x[i] + (v[i] * t);
    }

    vector<int> b = e;
    sort(b.begin(), b.end());

    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < n; ++i){
        e[i] = lower_bound(b.begin(), b.end(), e[i]) - b.begin() + 1;
    }

    vector<int> dp;
    for (int i = n-1; i+1; --i){
        auto it = upper_bound(dp.begin(), dp.end(), e[i]);
        if (it == dp.end()) dp.push_back(e[i]);
        else *it = e[i];
    }

    cout << dp.size();

    return 0;
}