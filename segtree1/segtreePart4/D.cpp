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

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v] = 1LL << (a[tl] - 1);
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        t[v] = t[2*v] | t[2*v+1];
    }

    void update(int v, int tl, int tr, int idx, int val){
        if (tl == tr){
            t[v] = 1LL << (val - 1);
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) update(2*v, tl, tm, idx, val);
        else update(2*v+1, tm+1, tr, idx, val);

        t[v] = t[2*v] | t[2*v+1];
    }

    int query(int v, int tl, int tr, int l, int r){
        if (r < tl || tr < l) return 0;
        if (l <= tl && tr <= r) return t[v];

        int tm = (tl + tr) / 2;
        int q1 = query(2*v, tl, tm, l, r),
        q2 = query(2*v+1, tm+1, tr, l, r);

        return q1 | q2;
    }
} st;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    st.build(1, 1, n);

    while (m--){
        int t, x, y; cin >> t >> x >> y;
        if (t == 1){
            int preans = st.query(1, 1, n, x, y);
            cout << __builtin_popcountll(preans) << '\n';
        }
        else {
            st.update(1, 1, n, x, y);
        }
    }

    return 0;
}