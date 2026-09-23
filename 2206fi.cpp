#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

int a[maxn];

struct SegmentTree {
    int t[maxn*4];

    void build(int v, int tl, int tr, int typ){
        if (tl == tr){
            t[v] = a[tl] + typ*tl;
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm, typ);
        build(2*v+1, tm+1, tr, typ);

        t[v] = min(t[2*v], t[2*v+1]);
    }

    void update(int v, int tl, int tr, int idx, int val, int typ){
        if (tl == tr){
            t[v] = val + idx * typ;
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) update(2*v, tl, tm, idx, val, typ);
        else update(2*v+1, tm+1, tr, idx, val, typ);

        t[v] = min(t[2*v], t[2*v+1]);
    }

    int query(int v, int tl, int tr, int l, int r){
        if (r < tl || tr < l) return INT_MAX;
        if (l <= tl && tr <= r) return t[v];

        int tm = (tl + tr) / 2;
        return min(query(2*v, tl, tm, l, r), query(2*v+1, tm+1, tr, l, r));
    }
} stn, stl;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    stn.build(1, 1, n, -1);
    stl.build(1, 1, n, 1);

    while (q--){
        int t; cin >> t;
        if (t == 1){
            int k, x; cin >> k >> x;
            stn.update(1, 1, n, k, x, -1);
            stl.update(1, 1, n, k, x, 1);
        }
        else {
            int k; cin >> k;
            int l = stn.query(1, 1, n, 1, k) + k;
            int r = stl.query(1, 1, n, k, n) - k;

            cout << min(l, r) << '\n';
        }
    }
    return 0;
}