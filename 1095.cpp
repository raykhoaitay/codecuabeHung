#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 7;

long long solver (long long a, long long b){
	long long result = 1;
	while (b){
		if (b & 1) result = (result * a) % mod;

		a = (a*a)%mod;
		b >>= 1;
	}

	return result;
}

int main(){
	int t; cin >> t;

	long long a, b;
	while (t--){
		cin >> a >> b;
		cout << solver(a, b) << "\n";
	}

	return 0;
}