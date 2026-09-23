#include <bits/stdc++.h>
#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout); }
void ray(string inp = "i.inp", string out = "o.out") {freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}

int mod = 1000000007;

int fact(int n){
	int result = 1; 
	for (int i = 2; i <= n; ++i){
		result = (result * i) % mod;
	}
	return result;
}

int dx, dy;
void ee(int a, int b){
	if (b == 0){
		dx = 1, dy = 0;
		return;
	}

	ee(b, a%b);
	int temp = dx;
	dx = dy;
	dy = temp - (a/b)*dy;
}

int modinv(int n){
	ee(n, mod);
	return (dx + mod) % mod;
}

int nCk(int n, int k){
	int top = fact(n);
	int bottom = (fact(n-k) * fact(k)) % mod;

	return (top * modinv(bottom)) % mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        ray();
    #endif
   	
    int a, b, n; cin >> a >> b >> n;
    int result = (nCk(a, n) * nCk(b, n)) % mod;
    cout << result << '\n';
    return 0;
}