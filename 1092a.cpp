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
   
   	int t; cin >> t;
   	while (t--){
    int n, k; cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) cin >> a[i];

    vector<pair<int, int>> b(n);
	for (int i = 0; i < n; ++i){
		cin >> b[i].first;
		b[i].second = (i+1);
	}

	sort(b.begin(), b.end(), [](const pair<int, int> &x, const pair<int, int> &y){
		return x.first > y.first;
	});
	
	int credit = 1000, i = 0, m = 0, turn, hmn = 0;
	vector<pair<int, int>> result;

	while (credit > 0 && i < n){
		if (b[i].first <= k){
			turn = (k - b[i].first + 1);
			credit -= turn;
			hmn += turn;
			result.push_back({b[i].second, turn});
			m++;
		}

		if (credit < 0){
			cout << -1;
			continue;
		}
		i++;
	}

	cout << hmn << '\n';
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].second; ++j){
			cout << result[i].first << ' ';
		}
	}
	cout << '\n';
	}
    return 0;
}