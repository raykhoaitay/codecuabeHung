#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5 + 10;
int a[maxn], pf[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, x; cin >> n >> x;

    pf[0] = 0;
    map<int, int> cow;
    cow[0]++;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pf[i] = pf[i-1] + a[i];
        cow[pf[i]]++;
    }

    int result = 0;
    for (int i = 0; i < n; ++i){
        cow[pf[i]]--;
        if (cow.count(pf[i] + x)) result += cow[pf[i] + x];
    }

    cout << result << '\n';
    return 0;
}