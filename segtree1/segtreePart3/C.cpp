#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

int a[maxn], start[maxn], res[maxn/2];

struct SegmentTree {
    int t[maxn * 4];

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
} st;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    memset(start, 0, sizeof(start));
    for (int i = 1; i <= 2*n; ++i){
        cin >> a[i];
        if (start[a[i]] == 0) start[a[i]] = i;
    }

    // for (int i = 1; i <= n; ++i) cout << start[i] << ' ';
    // cout << endl;

    st.init();
    for (int i = 1; i <= 2*n; ++i){
        if (i == start[a[i]]) continue;
        else {
            res[a[i]] = st.query(1, 1, 2*n, start[a[i]], i-1);

            st.update(1, 1, 2*n, start[a[i]], 1);
        }
    }

    for (int i = 1; i <= n; ++i) cout << res[i] << ' ';

    return 0;
}