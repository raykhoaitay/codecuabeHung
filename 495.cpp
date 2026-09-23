#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

struct Point {
    int x, y;

    Point (){};
} a[maxn];

struct Node {
    int sz, sum, msum, tl, tr;

    Node (){
        sz = -1; 
        sum = 0;
    };
};

int dist(const Point &a, const Point &b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

struct SegmentTree {
    Node t[maxn * 4];

    Node combine(const Node &l, const Node &r){
        if (l.sz == -1) return r;
        if (r.sz == -1) return l;
        
        Node result;

        result.sz = l.sz + r.sz;    

        int con = dist(a[l.tr], a[l.tr+1]);
        result.sum = l.sum + r.sum + con;

        int min1 = l.msum + r.sum + con;
        int min2 = l.sum + r.msum + con;
        int min3 = INT_MAX, min4 = INT_MAX;
        if (l.sz > 1){
            min3 = result.sum - con - dist(a[l.tr-1], a[l.tr]) + dist(a[l.tr-1], a[l.tr+1]);
        }
        if (r.sz > 1){
            min4 = result.sum - dist(a[r.tl], a[r.tl-1]) - dist(a[r.tl], a[r.tl+1]) + dist(a[r.tl-1], a[r.tl+1]);
        }

        result.msum = min(min(min1, min2), min(min3, min4));
        result.msum = min(result.msum, result.sum);

        result.tl = l.tl;
        result.tr = r.tr;

        return result;
    }

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v].sz = 1;
            t[v].sum = 0;
            t[v].msum = 0;
            t[v].tl = t[v].tr = tl;
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    void update(int v, int tl, int tr, int idx){
        if (tl == tr){
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

    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;

    st.build(1, 1, n);
    while (q--){
        char t; cin >> t;
        if (t == 'U'){
            int i; cin >> i;
            cin >> a[i].x >> a[i].y;

            st.update(1, 1, n, i);
        }
        else {
            int i, j; cin >> i >> j;

            Node result = st.query(1, 1, n, i, j);
            cout << result.msum << '\n';
        }
    }
    return 0;
}