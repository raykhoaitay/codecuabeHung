#include <bits/stdc++.h>

#define int long long

using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int zr = 0LL;
int mod = 1000000007;
const int maxn = 2e5+10;

int a[maxn];
struct Node {
    int sum, sf, pf, msum;

    Node (){
        sum = zr;
        sf = zr;
        pf = zr;
        msum = zr;
    };
};

struct SegmentTree {
    Node t[maxn * 4];

    Node combine(const Node &n1, const Node &n2){
        Node result;

        result.sum = n1.sum + n2.sum;
        result.pf = max(n1.pf, n1.sum + n2.pf);
        result.sf = max(n2.sf, n2.sum + n1.sf);
        result.msum = max(max(n1.msum, n2.msum), n1.sf + n2.pf);

        return result;
    }

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v].sum = a[tl];
            t[v].pf = max(zr, a[tl]);
            t[v].sf = max(zr, a[tl]);
            t[v].msum = max(zr, a[tl]);
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    void update(int v, int tl, int tr, int idx, int val){
        if (tl == tr){
            t[v].sum = val;
            t[v].pf = max(zr, val);
            t[v].sf = max(zr, val);
            t[v].msum = max(zr, val);
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) update(2*v, tl, tm, idx, val);
        else update(2*v+1, tm+1, tr, idx, val);

        t[v] = combine(t[2*v], t[2*v+1]);
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
    while (m--){
        int k, x; cin >> k >> x;
        st.update(1, 1, n, k, x);

        cout << st.t[1].msum << '\n';
    }

    return 0;
}