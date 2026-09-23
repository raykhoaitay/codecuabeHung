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
   	
   	int maxn = 1e6+5;
    vector<int> mark(maxn, 1);
    unordered_map<int, int> tprime;

    for (int i = 2; i < maxn; ++i){
    	if (mark[i]){
    		tprime[i*i]++;
    		for (int j = i * i; j < maxn; j += i) mark[j] = 0;
    	}
    }

    int n; cin >> n;
    int temp;
    for (int i = 0; i < n; ++i){
    	cin >> temp;

    	if (tprime[temp] == 1) cout << "YES\n";
    	else cout << "NO\n";
    }
    return 0;
}