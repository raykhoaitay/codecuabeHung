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
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<int> aa = a;

    sort(a.begin(), a.end());
    int c = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] != aa[i]){
            c = 1;
            break;
        }
    }

    if (c == 1){
        return k > 1;
    }
    else return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--){
        if (solver()) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}