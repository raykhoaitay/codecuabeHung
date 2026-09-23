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

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v] = a[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        t[v] = max(t[2*v], t[2*v+1]);
    }

    void update(int v, int tl, int tr, int idx, int val){
        if (tl == tr){
            t[v] += val;
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) update(2*v, tl, tm, idx, val);
        else update(2*v+1, tm+1, tr, idx, val);

        t[v] = max(t[2*v], t[2*v+1]);
    }

    int query(int v, int tl, int tr, int x){
        if (t[v] < x) return 0;
        if (tl == tr) return tl;

        int tm = (tl + tr) / 2;
        if (x <= t[2*v]) return query(2*v, tl, tm, x);
        if (x <= t[2*v+1]) return query(2*v+1, tm+1, tr, x);

        return 0;
    }
} st;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    st.build(1, 1, n);
    for (int i = 1; i <= m; ++i){
        int q; cin >> q;
        int qr = st.query(1, 1, n, q);

        if (qr){
            st.update(1, 1, n, qr, -q);
        }
        cout << qr << ' ';
    }

    return 0;
}