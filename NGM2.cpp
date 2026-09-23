#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {
    string inp = name + ".inp";
    string out = name + ".out";
    freopen(inp.c_str(), "r", stdin);
    freopen(out.c_str(), "w", stdout);
}

void ray() {
    freopen("i.inp", "r", stdin);
    freopen("o.out", "w", stdout);
}

int mod = 1000000007;
int maxn = 0;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, k; cin >> n >> k;
    vector<int> a(k, 0);

    for (int i = 0; i < k; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int result = 0;
    for (int mask = 1; mask < (1 << (k)); ++mask){
        int target = 1;
        int check = 0;
        for (int i = 0; i < k; ++i){
            if (mask & (1 << i)){
                target = (target * a[i]) / gcd(target, a[i]);
                if (target > n){
                    check = 1;
                    break;
                }
            }
        }

        if (check) continue;
        int x = n/target;
        if (__builtin_popcount(mask) % 2 == 0) result -= x;
        else result += x;
    }

    cout << n - result << '\n';
    return 0;
}