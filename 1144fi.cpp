#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

struct Query {
    int t, l, r;

    Query (){};
};

Query qr[maxn];
int a[maxn];

struct Fenwick {
    int t[1000000], n;

    void init(int n){
        this->n = n;
        memset(t, 0, sizeof(t));
    }

    void update(int idx, int val){
        for (; idx <= n; idx += (idx & -idx)) t[idx] += val;
    }

    int query(int idx){
        int ans = 0;
        for (; idx; idx -= (idx & -idx)) ans += t[idx];

        return ans;
    }
} fen;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, q; cin >> n >> q;
    vector<int> b = {0};

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        b.push_back(a[i]);
    }

    for (int i = 1; i <= q; ++i){
        char c; cin >> c;
        cin >> qr[i].l >> qr[i].r;
        
        if (c == '?'){
            qr[i].t = 1;
            b.push_back(qr[i].l);
        }
        else if (c == '!'){
            qr[i].t = 2;
        }
        b.push_back(qr[i].r);
    }

    sort(b.begin(), b.end());
    
    b.erase(unique(b.begin(), b.end()), b.end());

    fen.init(b.size() + 5);
    for (int i = 1; i <= n; ++i){
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        fen.update(a[i], 1);
    }

    for (int i = 1; i <= q; ++i){
        if (qr[i].t == 1) qr[i].l = lower_bound(b.begin(), b.end(), qr[i].l) - b.begin();
        qr[i].r = lower_bound(b.begin(), b.end(), qr[i].r) - b.begin();

        if (qr[i].t == 1){
            cout << fen.query(qr[i].r) - fen.query(qr[i].l - 1) << '\n';
        }
        else {
            fen.update(a[qr[i].l], -1);
            a[qr[i].l] = qr[i].r;
            fen.update(a[qr[i].l], 1);
        }
    }

    return 0;
}