#include <bits/stdc++.h>
#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout); }
void ray(string inp = "i.inp", string out = "o.out") {freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}

int mod = 1000000007;

int fact(int a){
	int result = 1;

	for (int i = 2; i <= a; ++i){
		result = (result * i) % mod;
	}

	return result;
}

int dx, dy;
void eE(int a, int b){
	if (b == 0){
		dx = 1; dy = 0;
		return;
	}

	eE(b, a%b);
	int temp = dx;
	dx = dy;
	dy = temp - (a / b) * dy;
}

int modinv(int n){
	eE(n, mod);
	return (dx + mod) % mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        ray();
    #endif
   
    string s; cin >> s;
    vector<int> cow(150, 0);

    for (char i : s) cow[i - 0]++;

    int result = fact(s.size());
	for (int i = 90; i < 150; ++i){
		if (cow[i] > 1){
			result = (result * modinv(fact(cow[i]))) % mod;
		}
	}

	cout << result;
    return 0;
}