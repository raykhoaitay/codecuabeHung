#include <bits/stdc++.h>
#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout); }
void ray(string inp = "i.inp", string out = "o.out") {freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}

int mod = 1000000007;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        ray();
    #endif
   
    int t; cin >> t;
    int n;
    vector<int> a;

    while (t--){
        cin >> n;
        int result = 0, temp;

        for (int i = 1; i <= n; ++i){
            cin >> temp;
            if (temp <= i) result++;
        }

        cout << result << '\n';
    }
    return 0;
}