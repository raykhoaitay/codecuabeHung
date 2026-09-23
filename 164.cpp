#include <bits/stdc++.h>
#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout); }
void ray(string inp = "i.inp", string out = "o.out") {freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}

int mod = 1000000007;
int maxn = 1e6+5;
vector<int> fact(maxn, 1);

int dx, dy;
void ee(int a, int b){
	if (b == 0){
		dx = 1, dy = 0;
		return;
	}
	ee(b, a%b);
	int temp = dx;
	dx = dy;
	dy = temp - (a/b) * dy;
}

int modinv(int n){
	ee(n, mod);
	return (dx + mod) % mod;
}

int nCk(int n, int k){
	int top = fact[n];
	int bottom = (fact[n-k] * fact[k]) % mod;
	return (top * modinv(bottom)) % mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        ray();
    #endif	
   	
   	for (int i = 2; i < maxn; ++i){
   		fact[i] = (fact[i-1] * i) % mod;
   	}

   	cout << modinv(2);
    // int q; cin >> q;

    // int n, k;
    // while (q--){
    // 	cin >> n >> k;
    // 	cout << nCk(n, k) << '\n';
    // }
    return 0;
}