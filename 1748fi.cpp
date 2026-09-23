#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

struct Fenwick {
    int t[maxn], n;

    void init(int n){
        this->n = n;
        memset(t, 0, sizeof(t));
    }

    void update(int idx, int val){
        for (; idx <= n; idx += (idx & -idx)){
            t[idx] += val;
            if (t[idx] >= mod) t[idx] -= mod;
        }
    }

    int query(int idx){
        int ans = 0;
        for (; idx; idx -= (idx & -idx)){
            ans += t[idx];
            if (ans >= mod) ans -= mod;
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

    int n; cin >> n;
    vector<int> a(n+1, 0);

    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    int maxx = 0;
    for (int i = 1; i <= n; ++i){
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        maxx = max(a[i], maxx);
    }

    fen.init(maxx+1);
    for (int i = 1; i <= n; ++i){
        int cc = fen.query(a[i]-1);
        fen.update(a[i], cc+1);
    }

    cout << fen.query(maxx+1);

    return 0;
}