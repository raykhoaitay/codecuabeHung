#include <bits/stdc++.h>
#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout); }
void ray(string inp = "i.inp", string out = "o.out") {freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}

int mod = 1000000007;
int maxn = 1e6+5;
vector<int> fact(maxn);

int dx, dy;

void eE(int a, int b){
	if (b == 0){
		dx = 1;
		dy = 0;
		return;
	} 

	eE(b, a%b);
	int temp = dx;
	dx = dy;
	dy = temp - (a/b)*dy;
}

int modinv(int a){
	eE(a, mod);
	return (dx + mod) % mod;
}

int solver (int a, int b){
	int top = fact[a],
	bottom = modinv((fact[b] * fact[a - b]) % mod);

	return (top * bottom) % mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        ray();
    #endif
   		
   	fact[1] = fact[0] = 1;
   	for (int i = 2; i < maxn; ++i){
   		fact[i] = (fact[i-1] * i) % mod;
   	}

    int n; cin >> n;
    int a, b;
    while (n--){
    	cin >> a >> b;
    	cout << solver(a, b) << '\n';
    }
    return 0;
}