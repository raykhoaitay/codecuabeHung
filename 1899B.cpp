#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 150010;
int a[maxn], pf[maxn];

int solver(){
    int n; cin >> n;

    vector<int> dvs;
    for (int i = 1; i * i <= n; ++i){
        if (n % i == 0){
            dvs.push_back(i);

            if (i != n/i) dvs.push_back(n/i);
        }
    }

    pf[0] = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pf[i] = pf[i-1] + a[i];
    }

    int k = 0;
    for (const int &x : dvs){
        int maxx = -1e18, minn = 1e18;

        for (int i = x; i <= n; i += x){
            maxx = max(maxx, pf[i] - pf[i-x]);
            minn = min(minn, pf[i] - pf[i-x]);
        }

        k = max(k, maxx - minn);
    }

    return k;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--){
        cout << solver() << '\n';
    }

    return 0;
}