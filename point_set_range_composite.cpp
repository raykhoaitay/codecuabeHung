#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 998244353;
const int maxn = 5e5+10;

struct Function {
    int a, b;

    Function (){};

    Function (int a, int b): a(a), b(b) {};
};

Function a[maxn];

struct SegmentTree {
    Function t[maxn*4];

    Function combine(const Function &f1, const Function &f2){
        Function result;

        result.a = (f1.a * f2.a) % mod;
        result.b = (f2.a * f1.b + f2.b) % mod;

        return result;
    }

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v] = a[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    void update(int v, int tl, int tr, int idx, int ax, int bx){
        if (tl == tr){
            t[v].a = ax;
            t[v].b = bx;
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) update(2*v, tl, tm, idx, ax, bx);
        else update(2*v+1, tm+1, tr, idx, ax, bx);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    Function query(int v, int tl, int tr, int l, int r){
        if (r < tl || tr < l) return {1, 0};
        if (l <= tl && tr <= r) return t[v];

        int tm = (tl + tr) / 2;
        return combine(query(2*v, tl, tm, l, r), query(2*v+1, tm+1, tr, l, r));
    }
} st;

int calc(const Function &f, int x){
    int result = f.a * x;
    result %= mod;
    result += f.b;
    result %= mod;

    return result;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, q; cin >> n >> q;
    for (int i = 0; i < n; ++i){
        cin >> a[i].a >> a[i].b;
    }

    st.build(1, 0, n-1);

    while (q--){
        int t, x, y, z; cin >> t >> x >> y >> z;
        if (t == 0){
            st.update(1, 0, n-1, x, y, z);
        }
        else {
            Function f = st.query(1, 0, n-1, x, y-1);
            cout << calc(f, z) << '\n';
        }
    }

    return 0;
}