#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 5e4+10;
int a[maxn], st[maxn], en[maxn], pf[maxn], sf[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    memset(st, 0, sizeof(st));
    memset(en, 0, sizeof(en));

    sort(a+1, a+n+1);

    int i = 1, j = 1;
    while (j <= n){
        while (a[j] - a[i] > k){
            i++;
        }
        en[j] = i;
        j++;
    }

    memset(pf, 0, sizeof(pf));
    memset(sf, 0, sizeof(sf));

    for (int i = 1; i <= n; ++i){
        pf[i] = max(pf[i-1], i - en[i] + 1);
    }

    i = n, j = n;
    while (j > 0){
        while (a[i] - a[j] > k){
            i--;
        }
        st[j] = i;
        j--;
    }

    for (int i = n; i > 0; --i){
        sf[i] = max(sf[i+1], st[i] - i + 1);
    }

    int result = -1e9;
    for (int i = 1; i < n; ++i){
        result = max(result, pf[i]+sf[i+1]);
    }

    cout << result;
    return 0;
}