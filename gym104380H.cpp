#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

int a[maxn];

struct Node {
    int pf, sf, pi, sz;

    Node(){
        pf = 0, sf = 0, pi = 0, sz = 0;
    };
};

struct SegmentTree {
    Node t[maxn*4];

    Node combine(const Node &l, const Node &r){
        Node result;

        result.sz = l.sz + r.sz;
        int pair = min(l.sf, r.pf);
        result.pi = l.pi + r.pi + pair;

        result.pf = l.pf;
        if (l.sz == l.pf + l.pi * 2 + pair) result.pf += r.pf - pair;

        result.sf = r.sf;
        if (r.sz == r.sf + r.pi * 2 + pair) result.sf += l.sf - pair;

        return result;
    }

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v].pi = 0;
            t[v].sz = 1;
            if (a[tl]) t[v].pf = 1;
            else t[v].sf = 1;

            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    void update(int v, int tl, int tr, int idx){
        if (tl == tr){
            t[v].sf ^= 1;
            t[v].pf ^= 1;
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) update(2*v, tl, tm, idx);
        else update(2*v+1, tm+1, tr, idx);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    Node query(int v, int tl, int tr, int l, int r){
        if (r < tl || tr < l) return Node();
        if (l <= tl && tr <= r) return t[v];

        int tm = (tl + tr) / 2;
        return combine(query(2*v, tl, tm, l, r), query(2*v+1, tm+1, tr, l, r));
    }
} st;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, q;
    string s; cin >> s;

    n = s.size();
    for (int i = 1; i <= n; ++i) a[i] = s[i-1] - '0';

    st.build(1, 1, n);
    cin >> q;

    while (q--){
        int k; cin >> k;

        if (k == 1){
            int x; cin >> x;
            st.update(1, 1, n, x);
        }
        else {
            int l, r; cin >> l >> r;

            Node result = st.query(1, 1, n, l, r);
            cout << result.sz - result.pi * 2 << '\n';
        }
    }

    return 0;
}