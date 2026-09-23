#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

int a[maxn];
struct SegmentTree {
    int t[maxn * 4];

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v] = a[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        t[v] = t[2*v] + t[2*v+1];
    }

    void update(int v, int tl, int tr, int idx){
        if (tl == tr){
            t[v] ^= 1;
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) update(2*v, tl, tm, idx);
        else update(2*v+1, tm+1, tr, idx);

        t[v] = t[2*v] + t[2*v+1];
    }

    int query(int v, int tl, int tr, int k){
        if (tl == tr){
            return tl;
        }

        int tm = (tl + tr) / 2;
        if (k <= t[2*v]){
            return query(2*v, tl, tm, k);
        }
        return query(2*v+1, tm+1, tr, k - t[2*v]);
    }
} st;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, q; cin >> n >> q;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    st.build(1, 0, n-1);
    while (q--){
        int t, x; cin >> t >> x;

        if (t == 1){
            st.update(1, 0, n-1, x);
        }
        else {
            cout << st.query(1, 0, n-1, x+1) << '\n';
        }
    }

    return 0;
}