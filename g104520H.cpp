#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
int a[maxn], b[maxn], c[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        c[i] = i * (n-i+1) * a[i];
    }
    for (int i = 1; i <= n; ++i) cin >> b[i];

    sort(c+1, c+n+1);
    sort(b+1, b+n+1, [](const int &a, const int &b){
        return a > b;
    });

    int summ = 0;
    for (int i = 1; i <= n; ++i){
        summ += c[i] * b[i];
    }  

    cout << summ << '\n'; 
    return 0;
}