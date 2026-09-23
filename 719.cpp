#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

int a[maxn], start[maxn];
struct SegmentTree {
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
} st;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    int n; cin >> n;
    st.init();

    memset(start, 0, sizeof(0));
    int cow = 0;
    for (int i = 1; i <= 2*n; ++i){
        cin >> a[i];
        if (!start[a[i]]){
            st.update(1, 1, 2*n, i, 1);
            start[a[i]] = i;
            continue;
        }      

        st.update(1, 1, 2*n, start[a[i]], 0);
        cow += st.query(1, 1, 2*n, start[a[i]]+1, i);
        // cout << cow << ' ' << a[i] << ' ' << start[a[i]]+1 << ' ' << i  << ' '<< st.query(1, 1, 2*n, start[a[i]]+1, i) << endl;
    }   

    // cout << st.query(1, 1, 2*n, 4, 4);
    cout << cow;
    return 0;
}