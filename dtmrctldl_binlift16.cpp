#include <bits/stdc++.h>

using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e6+10;

struct FenwickTree {
    int t[maxn], n;

    void init(int n){
        memset(t, 0, sizeof(t));
        this->n = n;
    }

    void update(int idx, int val){
        for (; idx <= n; idx += (idx & -idx)){
            t[idx] += val;
        }
    }

    int kth(int k){
        int idx = 0, sum = 0; 

        for (int j = 30; j+1; j--){
            if (idx + (1 << j) <= n){ 
                if (sum + t[idx + (1 << j)] < k){
                    sum += t[idx + (1 << j)];
                    idx += (1 << j);
                }
            }
        }

        if (idx + 1 <= 1e6+1) return idx + 1; 
        return -1;
    }
} fen;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int q; cin >> q;
    int n = 1e6+5;

    fen.init(n);
    while (q--){
        int t; cin >> t;
        if (t == 1){
            int x; cin >> x; 
            fen.update(x, 1);
        }
        else if (t == 2){
            int x; cin >> x;
            fen.update(x, -1);
        }
        else {
            int k; cin >> k;
            cout << fen.kth(k) << '\n';
        }
    }

    return 0;
}