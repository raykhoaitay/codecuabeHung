#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
const int INF = 1e18;

int a[maxn];
multiset<int> nul = {};
struct SegmentTree {
    multiset<int> t[maxn*4];

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v].insert(a[tl]);
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        t[v].insert(t[2*v].begin(), t[2*v].end());
        t[v].insert(t[2*v+1].begin(), t[2*v+1].end());
    }

    void update(int v, int tl, int tr, int idx, int val){
        t[v].erase(t[v].find(a[idx]));
        t[v].insert(val);
        if (tl == tr){
            a[tl] = val;
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) update(2*v, tl, tm, idx, val);
        else update(2*v+1, tm+1, tr, idx, val);
    }

    int query(int v, int tl, int tr, int l, int r, int x){
        if (r < tl || tr < l) return INF;
        if (l <= tl && tr <= r){
            auto it = t[v].lower_bound(x);
            if (it == t[v].end()) return INF;
            return *it;
        }

        int tm = (tl + tr) / 2;
        return min(query(2*v, tl, tm, l, r, x), query(2*v+1, tm+1, tr, l, r, x));
    }
} st;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    st.build(1, 1, n);
    while (q--){
        int t; cin >> t;
        if (t == 1){
            int idx, val; cin >> idx >> val;
            st.update(1, 1, n, idx, val);
        }
        else {
            int l, r, x; cin >> l >> r >> x;

            int qr = st.query(1, 1, n, l, r, x);
            if (qr == INF) cout << "NOT FOUND\n";
            else cout << qr << '\n';
        }
    }
    return 0;
}