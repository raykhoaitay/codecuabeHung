#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
int a[maxn];
int n, k, maxx;

bool check(int x){
    if (x < maxx) return false;

    int j = 1, part = 0, curr = 0;
    while (j <= n){
        while (curr + a[j] <= x && j <= n){
            curr += a[j];
            j++;
        }

        part++;
        curr = 0;
    }

    return part <= k;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    cin >> n >> k;
    maxx = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];

        maxx = max(maxx, a[i]);
    }

    int l = 1, r = 1e17;
    while (l < r){
        int mid = (r + l) / 2;

        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';
    return 0;
}