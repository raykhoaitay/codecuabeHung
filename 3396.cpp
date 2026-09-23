#include <bits/stdc++.h>
#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout); }
void ray(string inp = "i.inp", string out = "o.out") {freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}

int mod = 1000000007;
int maxn = 1e6+5;
vector<int> prime;

int solver(int l){
	int r = 2000;
	int whichone = floor(sqrt(l + r));
	int limit = upper_bound(prime.begin(), prime.end(), whichone) - prime.begin();

	vector<int> mark(r+1, 1);
	if (l == 0) mark[0] = mark[1] = 0;
	if (l == 1) mark[0] = 0;

	int target;
	for (int i = 0; i < limit; ++i){
		target = max(prime[i] * prime[i], (l/prime[i] + 1) * prime[i]);

		for (int j = target - l; j < r; j += prime[i]) mark[j] = 0;
	}

	return l + (find(mark.begin() + 1, mark.end(), 1) - mark.begin());
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        ray();
    #endif
   	
    vector<int> mark(maxn, 1);
    for (int i = 2; i < maxn; ++i){
    	if (mark[i]){
    		prime.push_back(i);
    		for (int j = i * i; j < maxn; j += i){
    			mark[j] = 0;
    		}
    	}
    }

    int t; cin >> t;
    int temp;

    while (t--){
    	cin >> temp;

    	cout << solver(temp) << '\n';
    }

    return 0;
}