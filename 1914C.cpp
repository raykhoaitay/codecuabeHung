#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
int a[maxn], b[maxn], maxx[maxn], pf[maxn];

int solver(){
    maxx[0] = 1;
    pf[0] = 0;
    int n, k; cin >> n >> k;



    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pf[i] = pf[i-1] + a[i];
    }

    for (int i = 1; i <= n; ++i){
        cin >> b[i];
        maxx[i] = max(maxx[i-1], b[i]);
    }

    int result = 0;
    for (int i = min(n, k); i > 0; --i){
        int temp = (pf[i]) + (maxx[i] * (k - i));
        result = max(result, temp);
    }

    return result;
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