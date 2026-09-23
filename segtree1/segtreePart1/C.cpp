#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

struct Node {
    int val, cow;

    Node (){
        val = 0;
        cow = 0;
    };

    Node (int val, int cow): val(val), cow(cow) {};
};

int a[maxn];
struct SegmentTree {
    vector<Node> t;

    void init(){
        t.assign(maxn*4, Node());
    }
    void print(){
        for (int i = 0; i < 20; ++i) cout << t[i].val << ' ';
        cout << '\n';
    }
    void minn(int v){
        if (t[2*v].val == t[2*v+1].val){
            t[v].val = t[2*v].val;
            t[v].cow = t[2*v].cow + t[2*v+1].cow;
        }
        else {
            if (t[2*v].val < t[2*v+1].val){
                t[v].val = t[2*v].val;
                t[v].cow = t[2*v].cow;
            }
            else {
                t[v].val = t[2*v+1].val;
                t[v].cow = t[2*v+1].cow;
            }
        }
    }

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v].val = a[tl];
            t[v].cow = 1;
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        minn(v);
    }

    void update(int v, int tl, int tr, int idx, int val){
        if (tl == tr){
            t[v].val = val;
            t[v].cow = 1;
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm){
            update(2*v, tl, tm, idx, val);
        }
        else update(2*v+1, tm+1, tr, idx, val);

        minn(v);
    }

    Node query(int v, int tl, int tr, int l, int r){
        if (tr < l || r < tl) return {INT_MAX, 0};
        if (l <= tl && tr <= r) return t[v];

        int tm = (tl + tr) / 2;
        Node s1 = query(2*v, tl, tm, l, r),
        s2 = query(2*v+1, tm+1, tr, l, r);

        if (s1.val == s2.val) return {s1.val, s1.cow + s2.cow};
        else if (s1.val > s2.val) return s2;
        else return s1;
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
        else {
            Node result = st.query(1, 0, n-1, x, y-1);
            cout << result.val << ' ' << result.cow << '\n';
        }
    }
    return 0;
}