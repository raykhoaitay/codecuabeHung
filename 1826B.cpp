#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
int a[maxn];

int solver(){
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int mgcd = abs(a[1] - a[n]);
    for (int i = 2; i <= n-i+1; ++i){
        mgcd = __gcd(mgcd, abs(a[i] - a[n-i+1]));
    }

    return mgcd;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--) cout << solver() << '\n';

    return 0;
}