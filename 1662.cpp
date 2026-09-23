#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 200010;
int a[maxn], pf[maxn];

int calc(int x){
    return x * (x-1) / 2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    int cow[n];
    memset(cow, 0, sizeof(cow));
    pf[0] = 0;
    cow[0] = 1;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pf[i] = pf[i-1] + a[i];
        cow[(pf[i] % n + n) % n]++;
    }

    int result = 0;
    for (int i = 0; i < n; ++i){
        result += calc(cow[i]);
    }

    cout << result << '\n';
    return 0;
}