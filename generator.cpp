#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000007;
const int maxn = 0;

mt19937_64 rng((uintptr_t) new char);

int rand(int l, int r){
    if (l > r) swap(l, r);
    return l + rng() % (r - l + 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = rand(5, 5000); 
    int q = rand(1, 1000); cout << n << ' ' << q << endl;
    for (int i = 1; i <= n; ++i) cout << rand(1, 1e9) << ' ';
    cout << '\n';
    
    for (int i = 1; i <= q; ++i){
        int t = rand(0, 1);
        int l = rand(0, n-2);
        int r = rand(l+1, n);

        cout << t << ' ' << l << ' ' << r;
        if (!t){
            int b = rand(1, 1e9), c = rand(0, 1e9);

            cout << ' ' << b << ' ' << c;
        }

        cout << endl;
    }

    return 0;
}