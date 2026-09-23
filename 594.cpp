#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 5e4+10;
int a[maxn], n, k;

bool check(int R){
    int i = 1, x;
    for (int _ = 0; _ < k; ++_){
        int x = a[i] + R;
        i = upper_bound(a+1, a+n+1, x + R) - a;

        if (i > n) return true;
    }

    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    //     ray();
    // #endif

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[n+1] = 1e10;

    sort(a+1, a+1+n);

    int l = 1, r = 1e9+10;
    while (l < r){
        int mid = (r + l) / 2;

        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';
    return 0;
}