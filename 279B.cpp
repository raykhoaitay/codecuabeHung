#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
int a[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, t; cin >> n >> t;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    } 

    int i = 1, j = 1;
    int maxx = -1e9, curr = 0;
    while (j <= n){
        curr += a[j];

        while (curr > t){
            curr -= a[i];
            i++;
        }
        if (curr <= t){
            maxx = max(maxx, j - i + 1);
        } j++;
    }

    cout << maxx << '\n';
    return 0;
}