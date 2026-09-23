#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

int a[maxn], diff[maxn];

struct Fenwick {
    int t[maxn], n;

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

    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    
    int n; cin >> n;
    fen.init(n+1);
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        int cc = fen.query(n+1) - fen.query(a[i]);
        diff[a[i]+1] += cc;
        diff[n] -= cc;

        if (a[i]) fen.update(a[i], 1);
    }

    int prev = 0;
    cout << prev << '\n'; 
    for (int i = 1; i < n; ++i){
        cout << prev + diff[i] << '\n';
        prev += diff[i];
    }

    return 0;
}