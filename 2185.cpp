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
   
    int k, n; cin >> k >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int result = 0, gifted, on;	
		
	for (int mask = 1; mask < (1 << n); ++mask){
		gifted = k;

		for (int i = 0; i < n; ++i){
			if (mask & (1 << i)){
				gifted /= a[i];
				if (!gifted) break;
			}
		}
		on = __builtin_popcount(mask);
		if (on % 2 != 0) result += gifted;
		else result -= gifted;

	}

	cout << result << '\n';
    return 0;
}