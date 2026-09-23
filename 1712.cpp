#include <bits/stdc++.h>
#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout); }
void ray(string inp = "i.inp", string out = "o.out") {freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}

int mod = 1000000007;

int powmod(int a, int b, int mod){
	int result = 1;
	while (b > 0){
		if (b & 1) result = (result * a) % mod;

		a = (a * a) % mod;
		b >>= 1;
	}

	return result;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        ray();
    #endif
   
    int n; cin >> n; 
    int a, b, c;
    while (n--){
    	cin >> a >> b >> c;
    	cout << powmod(a, powmod(b, c, mod-1), mod) << '\n';
    }

    return 0;	
}