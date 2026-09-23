#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
int a[maxn];

void solver(){
    int n; cin >> n;
    vector<int> result;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (i == 1){
            result.push_back(a[i]);
            continue;
        }
        
        result.push_back(a[i]);
        if (a[i] < a[i-1]){
            result.push_back(a[i]);
        }
    }

    cout << result.size() << '\n';

    for (const auto &x : result) cout << x << ' ';
    cout << '\n';
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