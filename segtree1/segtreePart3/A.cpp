#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

int a[maxn];

struct SegmentTree {
    int t[maxn*4];

    void init(){
        memset(t, 0, sizeof(t));
    }

    void update(int v, int tl, int tr, int idx){
        if (tl == tr){
            t[v]++;
            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) update(2*v, tl, tm, idx);
        else update(2*v+1, tm+1, tr, idx);

        t[v] = t[2*v] + t[2*v+1];
    }

    int query(int v, int tl, int tr, int l, int r){
        if (tr < l || r < tl) return 0;
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
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }   

    st.init();

    for (int i = 1; i <= n; ++i){
        st.update(1, 1, n, a[i]);
        if (a[i] == n){
            cout << 0 << ' ';
            continue;
        }
        cout << st.query(1, 1, n, a[i]+1,n) << ' ';
    }

    return 0;
}