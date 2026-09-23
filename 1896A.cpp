#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

int solver(){
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> aa = a;
    
    sort(aa.begin(), aa.end());
    for (int _ = 0; _ < 11; ++_)
    {for (int i = 1; i < n-1; ++i){
            if (a[i-1] < a[i] && a[i] > a[i+1]){
                swap(a[i], a[i+1]);
            }
        }}


    for (int i = 0; i < n; ++i){
        if (a[i] != aa[i]) return false;
    }

    return true;
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