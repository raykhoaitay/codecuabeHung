#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;

        if (n == 1){
            cout << "1\n";
            continue;
        }
        else if (n == 2){
            cout << "0\n";
            continue;
        }

        vector<int> e(27, 0), o(27, 0);
        vector<vector<int>> pf(27, vector<int> (maxn, 0));
    }

    return 0;
}