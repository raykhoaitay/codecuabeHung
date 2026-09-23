#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

int a[maxn];

struct Info {
    int sf, pf, ml;

    Info (){
        sf = 0;
        pf = 0;
        ml = 0;
    };
};
struct Node {
    int len;
    Info info[2];

    Node (){};
};

struct SegmentTree {
    Node t[maxn * 4];

    Node combine(const Node &l, const Node &r){
        Node result;

        result.len = l.len + r.len;

        for (int i = 0; i < 2; ++i){
            int pf = l.info[i].pf;
            pf += (l.info[i].pf == l.len) ? r.info[i].pf : 0;

            int sf = r.info[i].sf;
            sf += (r.info[i].sf == r.len) ? l.info[i].sf : 0;

            result.info[i].pf = pf;
            result.info[i].sf = sf;
            result.info[i].ml = max(max(l.info[i].ml, r.info[i].ml), l.info[i].sf + r.info[i].pf);
        }

        return result;
    }

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v].len = 1;
            Info temp;
            temp.sf = 1;
            temp.pf = 1;
            temp.ml = 1;

            t[v].info[a[tl]] = temp;
            return;
        } 

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    void update(int v, int tl, int tr, int idx){
        if (tl == tr){
            Info temp;
            temp.sf = 1;
            temp.pf = 1;
            temp.ml = 1;

            t[v].info[a[idx]] = temp;
            t[v].info[1 - a[idx]] = Info();

            return;
        }

        int tm = (tl + tr) / 2;
        if (idx <= tm) update(2*v, tl, tm, idx);
        else update(2*v+1, tm+1, tr, idx);

        t[v] = combine(t[2*v], t[2*v+1]);
    }
} st;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string s; cin >> s;

    n = s.size();
    for (int i = 1; i <= n; ++i){
        a[i] = s[i-1] - '0';
    }

    cin >> m;

    st.build(1, 1, n);
    while (m--){
        int k; cin >> k;

        a[k] ^= 1;
        st.update(1, 1, n, k);

        int zr = st.t[1].info[0].ml;
        int on = st.t[1].info[1].ml;
        cout << max(zr, on) << ' ';
    }
    return 0;
}