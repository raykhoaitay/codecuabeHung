#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
int a[maxn];
int n, m, c;

bool check(int x){
    int i = 1, j, cow = 0;
    for (int _ = 0; _ < m; ++_){
        i += cow;
        cow = 0;   
        while (cow < c && (a[i + cow] - a[i] <= x) && (i + cow) <= n){
            cow++;
        }
        if (i + cow > n) break;
    }

    return (i + cow == n + 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    // freopen("convention.in", "r", stdin);
    // freopen("convention.out", "w", stdout);

    cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    sort(a+1, a+n+1);
    int l = 0, r = a[n] - a[1] + 1;
    while (l < r){
        int mid = (r + l) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';

    return 0;
}