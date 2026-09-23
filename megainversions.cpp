#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

int a[maxn], pf[maxn], sf[maxn];
struct Fenwick {
    int t[maxn], n;

    void init(int n){
        this->n = n;
        memset(t, 0, sizeof(t));
    }
    
    void update(int idx, int val){
        for (; idx <= n; idx += (idx & -idx)) t[idx] += val;
    }

    int query(int idx){
        int ans = 0;
        for (; idx; idx -= (idx & -idx)) ans += t[idx];

        return ans;
    }
} fen;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    int maxx = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    memset(pf, 0, sizeof(pf));
    memset(sf, 0, sizeof(sf));

    fen.init(maxx+1);
    for (int i = 1; i <= n; ++i){
        int mk = fen.query(maxx+1) - fen.query(a[i]);

        pf[i] = mk;
        fen.update(a[i], 1);
    }

    fen.init(maxx+1);
    for (int i = n; i; --i){
        int mk = fen.query(a[i]-1);
        sf[i] = mk;
        fen.update(a[i], 1);
    }

    int ans = 0;
    for (int i = 2; i < n; ++i){
        ans += pf[i] * sf[i];
    }

    cout << ans;
    return 0;
}