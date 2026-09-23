#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 998244353;
const int maxn = 5e5+10;

int a[maxn];
struct Node {
    int lazyb, lazyc, sum;

    Node (){
        lazyb = 1;
        lazyc = 0;
        sum = 0;
    };
};

struct SegmentTree{
    Node t[maxn*4];

    Node combine(const Node &l, const Node &r){
        Node result;

        result.sum = (l.sum + r.sum) % mod;

        return result;
    }

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v].sum = a[tl];
            t[v].lazyb = 1;
            t[v].lazyc = 0;
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    void push(int v, int tl, int tr){
        if (t[v].lazyb == 1 && !t[v].lazyc) return;

        int l = 2*v, r = 2*v+1;
        int b = t[v].lazyb, c = t[v].lazyc;
        int tm = (tl + tr) / 2;

        t[l].lazyb = (t[l].lazyb * b) % mod;
        t[l].lazyc = (b * t[l].lazyc + c) % mod;
        t[l].sum = (((b * t[l].sum) % mod) + (tm - tl + 1) * c) % mod;

        t[r].lazyb = (t[r].lazyb * b) % mod;
        t[r].lazyc = (b * t[r].lazyc + c) % mod;
        t[r].sum = (((b * t[r].sum) % mod) + (tr - tm) * c) % mod;

        t[v].lazyb = 1;
        t[v].lazyc = 0;
    }

    void update(int v, int tl, int tr, int l, int r, int b, int c){
        if (r < tl || tr < l) return;

        if (l <= tl && tr <= r){
            t[v].sum = (((b * t[v].sum) % mod) + (tr - tl + 1) * c) % mod;
            t[v].lazyb = (t[v].lazyb * b) % mod;
            t[v].lazyc = (t[v].lazyc * b + c) % mod;
            return;
        }

        push(v, tl, tr);

        int tm = (tl + tr) / 2;
        update(2*v, tl, tm, l, r, b, c);
        update(2*v+1, tm+1, tr, l, r, b, c);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    int query(int v, int tl, int tr, int l, int r){
        if (r < tl || tr < l) return 0;
        if (l <= tl && tr <= r) return t[v].sum;

        push(v, tl, tr);

        int tm = (tl + tr) / 2;
        return (query(2*v, tl, tm, l, r) + query(2*v+1, tm+1, tr, l, r)) % mod;
    }
} st;  
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];

    st.build(1, 0, n-1);
    while (q--){
        int t, l, r, b, c; cin >> t;

        if (!t){
            cin >> l >> r >> b >> c;
            st.update(1, 0, n-1, l, r-1, b, c);
        }
        else {
            cin >> l >> r;
            cout << st.query(1, 0, n-1, l, r-1) << '\n';
        }
    }

    return 0;
}