#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

const int mod = 1000000007;
const int maxn = 1e6 + 10; 

struct Node {
    int l, r;
    long long sumF, sumF1, lazy;
};

vector<int> a;
vector<Node> st;
int fib[maxn];

void apply(int v, int x) {
    if (x == 0) return;
    long long nsumF = (fib[x - 1] * st[v].sumF + fib[x] * st[v].sumF1) % mod;
    long long nsumF1 = (fib[x] * st[v].sumF + fib[x + 1] * st[v].sumF1) % mod;
    
    st[v].sumF = nsumF;
    st[v].sumF1 = nsumF1;
    st[v].lazy += x;
}

void build(int v, int l, int r) {
    st[v].l = l;
    st[v].r = r;
    st[v].lazy = 0;
    
    if (l == r) {
        st[v].sumF = fib[a[l]] % mod;
        st[v].sumF1 = fib[a[l] + 1] % mod;
    } else {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        
        st[v].sumF = (st[2 * v].sumF + st[2 * v + 1].sumF) % mod;
        st[v].sumF1 = (st[2 * v].sumF1 + st[2 * v + 1].sumF1) % mod;
    }
}

void push(int v) {
    if (st[v].lazy == 0) return;
    
    apply(2 * v, st[v].lazy);
    apply(2 * v + 1, st[v].lazy);
    
    st[v].lazy = 0;
}

void update(int v, int tl, int tr, int l, int r, long long add) {
    if (l > r) return;
    
    if (l == tl && r == tr) {
        apply(v, add);
        return;
    }

    push(v);
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm), add);
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);

    st[v].sumF = (st[2 * v].sumF + st[2 * v + 1].sumF) % mod;
    st[v].sumF1 = (st[2 * v].sumF1 + st[2 * v + 1].sumF1) % mod;
}

long long query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return st[v].sumF;

    push(v);
    int tm = (tl + tr) / 2;
    return (query(2 * v, tl, tm, l, min(r, tm)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r)) % mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    }

    freopen("FIBSEQ.inp", "r", stdin);
    freopen("FIBSEQ.out", "w", stdout);

    int n, q; 
    cin >> n >> q;

    a.assign(n, 0);
    st.assign(4 * n, Node{});

    build(1, 0, n - 1);

    string type;
    int l, r;
    while (q--) {
        cin >> type;
        if (type == "D") {
            cin >> l >> r;
            update(1, 0, n - 1, l - 1, r - 1, 1);
        } else {
            cin >> l >> r;
            cout << query(1, 0, n - 1, l - 1, r - 1) << '\n';
        }
    }

    return 0;
}