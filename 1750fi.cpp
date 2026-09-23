#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
const int lg = 30;
int up[maxn][lg];
int n, q;

void init(){
    for (int j = 1; j < lg; ++j){
        for (int u = 1; u <= n; ++u){
            up[u][j] = up[up[u][j-1]][j-1];
        }
    }
}

int jump(int u, int k){
    for (int j = lg-1; j+1; j--){
        if (k & (1 << j)){
            u = up[u][j];
        }
    }

    return u;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    cin >> n >> q;
    memset(up, 0, sizeof(up));

    for (int i = 1; i <= n; ++i){
        int j; cin >> j;
        up[i][0] = j;
    }
    init();

    while (q--){
        int x, k; cin >> x >> k;
        cout << jump(x, k) << '\n';
    }

    return 0;
}