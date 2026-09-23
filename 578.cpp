#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

int a[maxn];
int O = 0LL;

struct Node {
    int lazy, sum, minn;

    Node (){
        lazy = O;
        sum = O;
        minn = INT_MAX;
    };
};

struct SegmentTree {
    Node t[maxn*4];

    Node combine(const Node &l, const Node &r){
        Node result;

        result.minn = min(l.minn, r.minn);
        result.sum = l.sum + r.sum;

        return result;
    }

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v].lazy = O;
            t[v].sum = a[tl];
            t[v].minn = a[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    void push(int v, int tl, int tr){
        if (t[v].lazy == 0) return;

        int tm = (tl + tr) / 2;

        int l = 2*v, r = 2*v+1, k = t[v].lazy;

        t[l].lazy += k;
        t[l].sum += (tm - tl + 1) * k;
        t[l].minn += k;

        t[r].lazy += k;
        t[r].sum += (tr - tm) * k;
        t[r].minn += k;

        t[v].lazy = 0;
    }

    void update(int v, int tl, int tr, int l, int r, int x){
        if (r < tl || tr < l) return;
        if (l <= tl && tr <= r){
            t[v].lazy += x;
            t[v].sum += (tr - tl + 1) * x;
            t[v].minn += x;
            return;
        }

        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(2*v, tl, tm, l, r, x);
        update(2*v+1, tm+1, tr, l, r, x);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    Node query(int v, int tl, int tr, int l, int r){
        if (r < tl || tr < l) return Node();
        if (l <= tl && tr <= r) return t[v];

        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return combine(query(2*v, tl, tm, l, r), query(2*v+1, tm+1, tr, l, r));
    }
} st; 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    st.build(1, 1, n);
    while (q--){
        char t; cin >> t;
        if (t == 'M'){
            int a, b; cin >> a >> b;

            Node result = st.query(1, 1, n, a, b);
            cout << result.minn << '\n';
        }
        else if (t == 'P'){
            int a, b, c; cin >> a >> b >> c;

            st.update(1, 1, n, a, b, c);
        }
        else if (t == 'S'){
            int a, b; cin >> a >> b;

            Node result = st.query(1, 1, n, a, b);
            cout << result.sum << '\n';
        }
    }

    return 0;
}