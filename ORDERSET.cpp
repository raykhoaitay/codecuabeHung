#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 4e5+10;

struct Query {
    int typ, val;

    Query (){
        typ = 0;
        val = 0;
    };
} a[maxn];

int old[maxn];

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

    int kth(int v, int tl, int tr, int k){
        if (k > t[v]) return 0;
        if (tl == tr) return tl;

        int tm = (tl + tr) / 2;
        if (k <= t[2*v]) return kth(2*v, tl, tm, k);
        return kth(2*v+1, tm+1, tr, k - t[2*v]);
    }

    int cow(int v, int tl, int tr, int x){
        if (x < tl) return 0;
        if (tr <= x) return t[v];

        int tm = (tl + tr) / 2;
        return cow(2*v, tl, tm, x) + cow(2*v+1, tm+1, tr, x);
    }
} st;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int q; cin >> q;
    vector<int> b = {0};

    for (int i = 1; i <= q; ++i){
        char t; cin >> t;
        if (t == 'I') a[i].typ = 1;
        else if (t == 'D') a[i].typ = 2;
        else if (t == 'K') a[i].typ = 3;
        else a[i].typ = 4;

        cin >> a[i].val;
        b.push_back(a[i].val);
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int n = maxn;
    for (int i = 1; i <= q; ++i){
        if (a[i].typ != 3){
            int temp = a[i].val;
            a[i].val = lower_bound(b.begin(), b.end(), a[i].val) - b.begin() + 1;
            old[a[i].val] = temp;
        }

        int tmp = a[i].typ;
        if (tmp == 1) st.update(1, 0, n, a[i].val, 1);
        if (tmp == 2) st.update(1, 0, n, a[i].val, 0);
        if (tmp == 3) {
            int qr = st.kth(1, 0, n, a[i].val);
            if (!qr) cout << "invalid\n";
            else cout << old[qr] << '\n';
        }
        if (tmp == 4) {
            cout << st.cow(1, 0, n, a[i].val-1) << '\n';
        }
    }

    return 0;
}