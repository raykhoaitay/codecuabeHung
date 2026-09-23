#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

int a[maxn];

struct Fenwick {
    int t[maxn], n;

    void init(int n){
        this->n = n;
        memset(t, 0, sizeof(t));
    }

    void update(int idx, int val){
        for (; idx <= n; idx += (idx & -idx)){
            t[idx] += val;
        }
    }

    int query(int idx){
        int ans = 0;
        for (; idx; idx -= (idx & -idx)){
            ans += t[idx];
        }

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
    fen.init(n);
    a[0] = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];

        fen.update(i, a[i] - a[i-1]);
    }

    while (q--){
        int t, x, y, u; cin >> t;

        if (t == 1){
            cin >> x >> y >> u;
            fen.update(x, u);
            fen.update(y+1, -u);
        }
        else {
            cin >> u;
            cout << fen.query(u) << '\n';
        }
    }

    return 0;
}