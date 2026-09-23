#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1510;
int n;
char a[maxn];

int solver(){
    int m; char c;
    cin >> m >> c;

    int i = 1, j = 1, used = 0;
    int maxx = -1e9;
    while (j <= n){
        if (a[j] != c) used++;
        while (used == m+1){
            if (a[i] != c) used--;
            i++;
        }

        maxx = max(j-i+1, maxx);
        j++;
    }

    return maxx;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    cin >> n; 
    char cc;
    for (int i = 1; i <= n; ++i){
        cin >> cc;
        a[i] = cc;
    }

    int q; cin >> q;
    while (q--) cout << solver() << '\n';

    return 0;
}