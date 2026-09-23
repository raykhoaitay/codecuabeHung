#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+20;
int a[maxn], b[maxn];
int n, m; 

bool query(int r){
    int i = 1, j = 1;

    while (i <= n && j <= m){
        int left = b[j] - r, right = b[j] + r;
        if (a[i] >= left && a[i] <= right){
            i++;
        }
        else if (a[i] > right){
            j++;
        }
        else if (a[i] < left) return false;
    }

    if (i == n+1) return true;
    return false;
} 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];

    int le = 0, ri = 2e9+15;
    while (le < ri){
        int mid = (le + ri) / 2;

        bool curr = query(mid);
        if (curr) ri = mid;
        else le = mid + 1;
    }

    cout << le << '\n';

    return 0;
}