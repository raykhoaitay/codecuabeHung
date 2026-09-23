#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 20;

struct Movie {
    int d, c;
    vector<int> st;

    Movie (){};
} a[maxn];

int dp[(1 << maxn)];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("movie.in", "r", stdin);
    freopen("movie.out", "w", stdout);

    int n, l; cin >> n >> l;
    for (int i = 0; i < n; ++i){
        cin >> a[i].d >> a[i].c;

        for (int j = 0; j < a[i].c; ++j){
            int temp; cin >> temp;
            a[i].st.push_back(temp);
        }
    }

    for (int i = 0; i < (1 << n); ++i){
        dp[i] = -1;
    }

    for (int i = 0; i < n; ++i){
        int f = lower_bound(a[i].st.begin(), a[i].st.end(), 0) - a[i].st.begin();
        if (f >= a[i].st.size()) continue;

        if (a[i].st[f] == 0) dp[(1 << i)] = a[i].d;
    }

    for (int mask = 1; mask < (1 << n); ++mask){
        for (int j = 0; j < n; ++j){
            int nmask = mask | (1 << j);
            if (nmask == mask || dp[mask] == -1) continue;

            int f = upper_bound(a[j].st.begin(), a[j].st.end(), dp[mask]) - a[j].st.begin() - 1;
            if (f >= a[j].st.size()) continue;
            if (a[j].st[f] + a[j].d < dp[mask]) continue;

            dp[nmask] = max(dp[nmask], a[j].st[f] + a[j].d);
        }
    }

    int minn = 1e9;
    for (int mask = 0; mask < (1 << n); ++mask){
            if (dp[mask] >= l){
                int cow = __builtin_popcount(mask);

                minn = min(minn, cow*1LL);
            }
        
    }

    if (minn != 1e9) cout << minn;
    else cout << -1;
    return 0;
}