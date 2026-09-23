#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

int a[maxn];
int zero = 0LL;
struct Node {
    int sum, maxpf, maxsf, maxsum;

    Node (){
        sum = 0LL,
        maxpf = 0LL,
        maxsf = 0LL,
        maxsum = 0LL;
    };
};

struct SegmentTree {
    Node t[maxn*4];

    Node combine(const Node &n1, const Node &n2){
        Node result;

        result.sum = n1.sum + n2.sum;
        result.maxpf = max(n1.sum + n2.maxpf, n1.maxpf);
        result.maxsf = max(n2.sum + n1.maxsf, n2.maxsf);
        result.maxsum = max(max(n1.maxsum, n2.maxsum), n1.maxsf + n2.maxpf);

        return result;
    }

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v].sum = a[tl];
            t[v].maxpf = max(zero, a[tl]);
            t[v].maxsf = max(zero, a[tl]);
            t[v].maxsum = max(zero, a[tl]);
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
            t[v].maxpf = max(val, zero);
            t[v].maxsf = max(val, zero);
            t[v].maxsum = max(val, zero);
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) update(2*v, tl, tm, idx, val);
        else update(2*v+1, tm+1, tr, idx, val);

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

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    st.build(1, 1, n);
    cout << st.query(1, 1, n, 1, n).maxsum;
    return 0;
}