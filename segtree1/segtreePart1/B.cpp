#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

int a[maxn];

struct SegmentTree {
    int t[maxn*4];

    void init (){
        memset(t, 0, sizeof(t));
    }

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v] = a[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        t[v] = min(t[2*v], t[2*v+1]);
    }

    void update(int v, int tl, int tr, int idx, int val){
        if (tl == tr){
            t[v] = val;
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) update(2*v, tl, tm, idx, val);
        else update(2*v+1, tm+1, tr, idx, val);

        t[v] = min(t[2*v], t[2*v+1]);
    }

    int query(int v, int tl, int tr, int l, int r){
        if (tr < l || r < tl) return INT_MAX;
        if (l <= tl && tr <= r) return t[v];

        int tm = (tl + tr) / 2;
        return min(query(2*v, tl, tm, l, r), query(2*v+1, tm+1, tr, l, r));
    }
} st;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];

    st.init();
    st.build(1, 0, n-1);

    while (m--){
        int typ, x, y; cin >> typ >> x >> y;
        if (typ == 1) st.update(1, 0, n-1, x, y);
        else cout << st.query(1, 0, n-1, x, y-1) << '\n';
    }

    return 0;
}