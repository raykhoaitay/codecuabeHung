#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;
vector<int> a;
int n, k, median;

bool check(int x){
    int kk = k;
    int target = upper_bound(a.begin()+1, a.end(), x) - a.begin();

    for (int i = median; i < target; ++i){
        kk -= (x - a[i]);
    }

    return kk >= 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    cin >> n >> k;
    a.assign(n+1, 0);

    for (int i = 1; i <= n; ++i) cin >> a[i];

    median = n/2 + 1;
    sort(a.begin()+1, a.end());

    int l = a[median], r = a[median] + k + 1000;
    while (l < r){
        int mid = (r + l + 1) / 2;

        if (check(mid)) l = mid;
        else r = mid - 1; 
    }

    cout << l << '\n';

    return 0;
}