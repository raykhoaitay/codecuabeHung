#include <bits/stdc++.h>
#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout); }
void ray(string inp = "i.inp", string out = "o.out") {freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}

int mod = 1000000007;
int maxn = 1e6;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        ray();
    #endif
   
    int t; cin >> t;
    vector<int> a;
    while (t--){
    	int n; cin >> n;
    	a.assign(n, 0);
    	for (int i = 0; i < n; ++i){
    		cin >> a[i];
    	}

    	int check = -1;
    	for (int i = n-1; i > 0; --i){
    		if (a[i] > a[i-1]){
    			check = i-1;
    			break;
    		}
    	}

    	if (check == -1){
    		cout << -1 << '\n';
    		continue;
    	}

    	int sw = n - 1 - (upper_bound(a.rbegin(), a.rbegin() + (n - check - 1), a[check]) - a.rbegin());
    	int temp = a[check];
    	a[check] = a[sw];
    	a[sw] = temp;
    	sort(a.begin() + check + 1, a.end());
    	for (int i = 0; i < n; ++i) cout << a[i];

    	cout << '\n';
    }
    return 0;
}