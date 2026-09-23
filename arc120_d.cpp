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
   
    int n; cin >> n;
    n *= 2;
    vector<int> a(n);
    vector<pair<int, int>> bin(n);
    vector<int> mark(n, 0);

    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    	bin[i].first = a[i];
    	bin[i].second = i;
    }

    sort(bin.begin(), bin.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
    	return a.first > b.first;
    });

    for (int i = 0; i < n/2; ++i){
    	mark[bin[i].second] = 1;
    }

    stack<int> s;
    s.push(0);
    vector<int> result(n*2, 0);
    result[0] = 1;

    for (int i = 1; i < n; ++i){
        if (s.empty()){
            s.push(i);
            continue;
        }

    	int x = s.top();
		if (mark[i] == mark[x]){
			s.push(i);
		}
		else {
			s.pop();
			result[i] = 2;
			result[x] = 1;
		}
    }

    for (int i = 0; i < n; ++i){
    	if (result[i] == 1) cout << '(';
    	else cout << ')';
    }
    return 0;
}