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
   
    int n, l; cin >> n >> l;
    vector<double> a(n);
    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    }

    sort(a.begin(), a.end());
    double maxx = max(a[0] - 0, l - a[n-1]);

    for (int i = 0; i < n-1; ++i){
        maxx = max(maxx, (abs(a[i]-a[i+1])/2));
    }

    cout << fixed << setprecision(9) << maxx;
    return 0;
}