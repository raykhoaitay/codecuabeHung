//cses.fi

#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
int a[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    int curr = 0, cow = 0, i = 1, j = 1;
    while (i <= j && j <= n){
        curr += a[j];

        while (curr >= m){
            if (curr == m) cow++;
            curr -= a[i];
            i++;
        }
        j++;
    }

    cout << cow;

    return 0;
}