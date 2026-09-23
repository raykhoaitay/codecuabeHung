#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
int a[maxn], b[maxn], fact[maxn];

int solver(){
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    int i = 1, j = 1;
    int result = 1;
    while (i <= n){
        while (a[i] > b[j] && j <= n){
            j++;
        }

        result = (result * (j - i)) % mod;
        i++;
    }
    
    return result;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--) cout << solver() << '\n';

    return 0;
}