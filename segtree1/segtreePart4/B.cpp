#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

struct Matrix {
    int tb[2][2];

    Matrix (){};
};

Matrix a[maxn];

Matrix combine(const Matrix &a, const Matrix &b){
    Matrix result;

    result.tb[0][0] = ((a.tb[0][0] * b.tb[0][0]) + (a.tb[0][1] * b.tb[1][0])) % mod;
    result.tb[0][1] = ((a.tb[0][0] * b.tb[0][1]) + (a.tb[0][1] * b.tb[1][1])) % mod;
    result.tb[1][0] = ((a.tb[1][0] * b.tb[0][0]) + (a.tb[1][1] * b.tb[1][0])) % mod;
    result.tb[1][1] = ((a.tb[1][0] * b.tb[0][1]) + (a.tb[1][1] * b.tb[1][1])) % mod;

    return result;
}

struct Segtree {
    Matrix t[maxn*4];

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

    void update(int v, int tl, int tr, int idx, const Matrix &val){
        if (tl == tr){
            t[v] = val;
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) update(2*v, tl, tm, idx, val);
        else update(2*v+1, tm+1, tr, idx, val);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    Matrix query(int v, int tl, int tr, int l, int r){
        if (r < tl || tr < l){
            Matrix nn;
            nn.tb[0][0] = nn.tb[1][1] = 1;
            nn.tb[0][1] = nn.tb[1][0] = 0;

            return nn;
        }
        if (l <= tl and tr <= r) return t[v];

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

    int r, n, q; cin >> r >> n >> q;

    mod = r;

    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < 2; ++j){
            for (int k = 0; k < 2; ++k) cin >> a[i].tb[j][k];
        }
    }

    st.build(1, 1, n);
    while (q--){
        int x, y; cin >> x >> y;

        Matrix result = st.query(1, 1, n, x, y);
        for (int j = 0; j < 2; ++j){
            for (int k = 0; k < 2; ++k){
                cout << result.tb[j][k] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}