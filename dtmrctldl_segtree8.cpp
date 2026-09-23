#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
string s;

int pow2k[maxn];

struct Node {
    int val, len;

    Node (){
        val = 0;
        len = 0;
    };
};

struct SegmentTree {
    Node t[maxn*4];

    Node combine(const Node &l, const Node &r){
        Node result;

        result.len = l.len + r.len;
        result.val = ((l.val * pow2k[r.len]) % mod) + r.val;
        result.val %= mod;

        return result;
    }

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v].val = s[tl-1] - '0';
            t[v].len = 1;
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    void update(int v, int tl, int tr, int idx){
        if (tl == tr){
            t[v].val = 0;
            t[v].len = 0;
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

struct Fenwick {
    int t[maxn];
    int n;

    void init(int n){
        this->n = n;
    }

    void update(int idx, int val){
        for (; idx <= n; idx += (idx & -idx)) t[idx] += val;
    }
    
    int kth(int k){
        int idx = 0, sum = 0;
        for (int j = 20; j+1; j--){
            if (idx + (1 << j) <= n){
                if (sum + t[idx + (1 << j)] < k){
                    sum += t[idx + (1 << j)];
                    idx += (1 << j);
                }
            }
        }

        return idx + 1;
    }
} bit;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, q; cin >> n >> q;
    cin >> s;

    pow2k[0] = 1;
    for (int i = 1; i < maxn; ++i){
        pow2k[i] = pow2k[i-1] * 2;
        pow2k[i] %= mod;
    }

    st.build(1, 1, n);
    bit.init(n);

    for (int i = 1; i <= n; ++i){
        bit.update(i, 1);
    }

    cout << st.t[1].val << endl;
    while (q--){
        int t; cin >> t;
        if (t == 1){
            int p; cin >> p;

            p = bit.kth(p);
            st.update(1, 1, n, p);
            bit.update(p, -1);
        }
        else {
            int l, r; cin >> l >> r;

            l = bit.kth(l);
            r = bit.kth(r);

            cout << st.query(1, 1, n, l, r).val << '\n';
        }
    }

    return 0;
}