#include <bits/stdc++.h>

using namespace std;

vector<int> prime;
int n = 1000005;
int siz;

int solver(int x){
	int i = 0, result = 1, cow = 0;
	while (1LL * prime[i] * prime[i] <= x){
		while (x % prime[i] == 0){
			x /= prime[i];
			cow++;
		}
		if (cow != 0) result *= (cow+1);
		cow = 0;
		i++;
	}
	
	if (x > 1) result *= 2;
	return result;
}

int main(){
	freopen("i.inp", "r", stdin);
	freopen("o.out", "w", stdout);
	vector<int> mark(n, 1);

	for (int i = 2; i < n; ++i){
		if (mark[i]){
			prime.push_back(i);
			for (long long j = 1LL* i * i; j < n; j += i){
				mark[j] = 0;
			}
		}
	}

	int t; cin >> t;
	int x;
	siz = prime.size();
	while (t--){
		cin >> x;
		cout << solver(x) << '\n';
	}

	return 0;
}