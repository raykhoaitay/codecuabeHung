#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
int a[maxn];
int n, x; 

bool check(int h){
    int amt = 0;

    for (int i = 1; i <= n; ++i){
        if (h <= a[i]) continue;
        amt += (h - a[i]);
    }

    return amt <= x;
}

int solver(){
    cin >> n >> x;

    int maxx = -1;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }

    int l = 1, r = x+maxx;
    while (l < r){
        int mid = (r + l + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    return l; 
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--) cout << solver() << '\n';

    return 0;
}