#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
int a[maxn], pf[maxn];

int solver(){
    int n, k; cin >> n >> k;
    pf[0] = 0;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    sort(a+1, a+n+1);

    for (int i = 1; i <= n; ++i){
        pf[i] = pf[i-1] + a[i];
    }

    int maxx = -1e9;
    for (int i = 0; i <= k; ++i){
        int curr1 = pf[i*2] - pf[0],
        curr2 = pf[n] - pf[n-(k-i)];
        maxx = max(maxx, pf[n] - (curr1 + curr2));
    }

    return maxx;
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