#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

void solver(){
    int n; cin >> n;

    int yin = 0, yang = 0;
    for (int i = 0; i < n-1; ++i){
        int temp; cin >> temp;
        if (temp < 0) yin += temp;
        else yang += temp;
    }

    if (abs(yin) < yang){
        cout << -1 * (yang - abs(yin));
    }
    else cout << abs(yin) - yang;

    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--){
        solver();
    }

    return 0;
}