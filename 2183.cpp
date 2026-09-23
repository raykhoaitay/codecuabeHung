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
   
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
	
	if (a[0] > 1){
		cout << 1;
		return 0;
	}
	int cur = a[0];
	int result = 0;
	for (int i = 1; i < n; ++i){
		if (cur + 1 < a[i]){
			result = cur + 1;
			break;
		}

		else cur += a[i];
	}

	if (result == 0){
		cout << cur+1;
	}
	else cout << result;

    return 0;
}