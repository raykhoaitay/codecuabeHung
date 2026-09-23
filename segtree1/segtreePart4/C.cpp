#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

int a[maxn];
struct Node {
    int inv, freq[41];

    Node (){
        inv = 0;
        memset(freq, 0, sizeof(freq));
    }
};

Node combine(const Node &a, const Node &b){
    Node result;

    result.inv = a.inv + b.inv;
    int pf = 0;
    for (int i = 0; i < 41; ++i) pf += b.freq[i];

    for (int i = 40; i; --i){
        pf -= b.freq[i];
        result.freq[i] = a.freq[i] + b.freq[i];
        result.inv += a.freq[i] * pf;
    }    

    return result;
}

struct SegmentTree {
    Node t[maxn*4];

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v].freq[a[tl]] = 1;
            return; 
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    void update(int v, int tl, int tr, int idx, int val){
        if (tl == tr){
            memset(t[v].freq, 0, sizeof(t[v].freq));
            t[v].freq[val] = 1;
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

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    st.build(1, 1, n);
    // for (int k = 1; k <= 5; ++k){
    //     for (int j = 0; j < 4; ++j){
    //         cout << st.t[k].freq[j] << ' ';
    //     }
    //     cout << endl;
    // }

    while (q--){
        int t, x, y; cin >> t >> x >> y;
        if (t == 2){
            st.update(1, 1, n, x, y);
        }
        else {
            Node result = st.query(1, 1, n, x, y);
            cout << result.inv << '\n';
        }
    }

    return 0;
}