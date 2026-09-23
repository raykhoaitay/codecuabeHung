#include <bits/stdc++.h>
#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout); }
void ray(string inp = "i.inp", string out = "o.out") {freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}

int mod = 1000000007;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    int n;
    vector<int> a;
    int change, target;
    while (t--){
    	cin >> n;
    	a.assign(n, 0);
    	change = 0;

    	for (int i = 0; i < n; ++i) cin >> a[i];
    	for (int i = 0; i < n; ++i) cin >> a[i];
    	if (a[0] > __gcd(a[0], a[1])){
    		change++;
    		a[0] = __gcd(a[0], a[1]);
    	}
    	if (a[n-1] > __gcd(a[n-1], a[n-2])){
    		change++;
    		a[n-1] = __gcd(a[n-1], a[n-2]);
    	}

    	for (int i = 1; i < n-1; ++i){
    		target = lcm(__gcd(a[i], a[i-1]), __gcd(a[i], a[i+1]));
    		if (a[i] > target){
    			a[i] = target;
    			change++;
    		}
    	}

    	cout << change << '\n';
    }

    return 0;
}