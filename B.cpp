#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

bool solver(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    string s; cin >> s;
    for (int i = 0; i < n; ++i){
        a[i] = s[i] - '0';
    }

    for (int i = 0; i < n - k; ++i){
        if (a[i] == 1){
            a[i] = 0;
            a[i+k] = 1 - a[i+k];
        }
    }

    for (int i = 0; i < n; ++i){
        if (a[i] == 1) return 0;
    }

    return 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--){
        if (solver()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}