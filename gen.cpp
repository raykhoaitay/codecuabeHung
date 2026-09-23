#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

mt19937_64 rng((uintptr_t) new char);

int rand(int a, int b){
    if (b < a) swap(a, b);
    return a + rng() % (b - a + 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = rand(3, 9);
    int q = rand(5, 10);

    cout << n << ' ' << q << '\n';

    for (int i = 1; i <= n; ++i) cout << rand(1, 10) << ' ';
    cout << '\n';

    for (int i = 1; i <= q; ++i){
        int t = rand(1, 2);

        if (t == 1){
            int idx = rand(1, n);
            int val = rand(4, 14);

            cout << t << ' ' << idx << ' ' << val << '\n';
        }
        else {
            int l = rand(2, n/2);
            int r = rand(l, n);
            int x = rand(1, 40);

            cout << t << ' ' << l << ' ' << r << ' ' << x << '\n';
        }
    }

    return 0;
}