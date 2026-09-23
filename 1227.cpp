#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
int a[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    char c;
    for (int i = 1; i <= n; ++i){
        cin >> c;
        if (c == 'G') a[i] = 1;
        else a[i] = 0;
    }

    int maxx, turn;
    int c = 0, l = 0;

    if (a[1] == 1) l++;
    if (a[2] == 2) c++;
    
    for (int i = 4; i <= n; i += 2){

    }

    return 0;
}