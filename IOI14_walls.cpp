#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e6+10;

int a[maxn], result[maxn];

struct Node {
    int mi, ma, lzmi, lzma;

    Node (){};
};

struct SegmentTree {
    Node t[maxn*4];

    Node combine(const Node &l, const Node &r){
        Node result;

        result.mi = min(l.mi, r.mi);
        result.ma = max(l.ma, r.ma);

        return result;
    }

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v].mi = a[tl];
            t[v].ma = a[tl];
            t[v].lzmi = 0;
            t[v].lzma = 0;

            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    void pushmin(int v, int tl, int tr){
        if (t[v].lzmi == 0) return;

        int l = v*2, r = v*2 + 1;

        if (t[l].mi < t[v].lzmi){
            t[l].mi = t[v].lzmi;
            t[l].lzmi = t[v].lzmi;
        }
        t[l].ma = max(t[l].mi, t[l].ma);

        if (t[r].mi < t[v].lzmi){
            t[r].mi = t[v].lzmi;
            t[r].lzmi = t[v].lzmi;
        }
        t[r].ma = max(t[r].mi, t[r].ma);

        t[v].lzmi = 0;
    }

    void pushmax(int v, int tl, int tr){
        if (t[v].lzma == 0) return;

        int l = v*2, r = v*2 + 1;

        if (t[l].ma > t[v].lzma){
            t[l].ma = t[v].lzma;
            t[l].lzma = t[v].lzma;
        }
        t[l].mi = min(t[l].mi, t[l].ma);

        if (t[r].ma > t[v].lzma){
            t[r].ma = t[v].lzma;
            t[r].lzma = t[v].lzma;
        }
        t[r].mi = min(t[r].mi, t[r].ma);

        t[v].lzma = 0;
    }

    void updatemin(int v, int tl, int tr, int l, int r, int mi){
       if (r < tl || tr < l) return;
        if (l <= tl && tr <= r){
            if (t[v].mi < mi){
                t[v].lzmi = mi;
                t[v].mi = mi;

                return;
            }
        }

        int tm = (tl + tr) / 2;
        pushmin(v, tl, tr);
        updatemin(2*v, tl, tm, l, r, mi);
        updatemin(2*v+1, tm+1, tr, l, r, mi);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    void updatemax(int v, int tl, int tr, int l, int r, int ma){
        if (r < tl || tr < l) return;
        if (l <= tl && tr <= r){
            if (t[v].ma > ma){
                t[v].lzma = ma;
                t[v].ma = ma;

                return;
            }
        }

        int tm = (tl + tr) / 2;
        pushmax(v, tl, tr);
        updatemax(2*v, tl, tm, l, r, ma);
        updatemax(2*v+1, tm+1, tr, l, r, ma);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    void query(int v, int tl, int tr){
        if (tl == tr){
            result[tl] = t[v].
        }
    }
} st;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, k; cin >> n >> k;

    for (int i = 0; i < n; ++i) cin >> a[i];

    return 0;
}