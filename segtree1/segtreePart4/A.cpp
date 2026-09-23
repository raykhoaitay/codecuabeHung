#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".in"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

int a[maxn];

struct segTree {
    int t[maxn*4];

    void init(){
        memset(t, 0, sizeof(t));
    }

    void update(int v, int tl, int tr, int idx, int val){
        if (tl == tr){
            t[v] = val;
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) update(2*v, tl, tm, idx, val);
        else update(2*v+1, tm+1, tr, idx, val);

        t[v] = t[2*v] + t[2*v+1];
    }

    int query(int v, int tl, int tr, int l, int r){
        if (r < tl || tr < l) return 0;
        if (l <= tl && tr <= r) return t[v];

        int tm = (tl + tr) / 2;
        return query(2*v, tl, tm, l, r) + query(2*v+1, tm+1, tr, l, r);
    }
} s1, s2, s3, s4;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;

    s1.init();
    s2.init();
    s3.init();
    s4.init();

    for (int i = 1; i <= n; ++i){
        cin >> a[i];

        if (i % 2){
            s1.update(1, 1, n, i, a[i]);
            s3.update(1, 1, n, i, -a[i]);
        }
        else {
            s2.update(1, 1, n, i, a[i]);
            s4.update(1, 1, n, i, -a[i]);
        }
    }

    int q; cin >> q;
    while (q--){
        int t, x, y; cin >> t >> x >> y;

        if (!t){
            if (x % 2){
                s1.update(1, 1, n, x, y);
                s3.update(1, 1, n, x, -y);
            }
            else {
                s2.update(1, 1, n, x, y);
                s4.update(1, 1, n, x, -y);
            }
        }
        else {
            if (x % 2){
                cout << s1.query(1, 1, n, x, y) + s4.query(1, 1, n, x, y) << '\n';
            }
            else cout << s2.query(1, 1, n, x, y) + s3.query(1, 1, n, x, y) << '\n';
        }
    }

    return 0;
}