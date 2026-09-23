#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

int solver(){
    int n, x; cin >> n >> x;
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a.push_back(x);
        
    int maxx = -1;
    for (int i = 0; i <= n; ++i){
        maxx = max(maxx, a[i+1] - a[i]);
    }

    maxx = max(maxx, (a[n+1] - a[n]) * 2);

    return maxx;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--){
        cout << solver() << '\n';
    }

    return 0;
}