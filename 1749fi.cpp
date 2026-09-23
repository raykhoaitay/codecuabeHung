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

    int findK(int k){
        int idx = 0;
        int sum = 0;

        for (int i = 1 << 18; i; i >>= 1){
            if (idx + i <= n && sum + t[idx + i] < k){
                sum += t[idx + i];
                idx += i;
            }
        }

        return idx + 1;
    }
} fen;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    fen.init(n);
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        fen.update(i, 1);
    }

    for (int i = 1; i <= n; ++i){
        int p; cin >> p;
        int k = fen.findK(p);
        fen.update(k, -1);
        cout << a[k] << ' ';
    }

    return 0;
}