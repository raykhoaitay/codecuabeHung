#include <bits/stdc++.h>
#define int long long
using namespace std;

void ray(string name){string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray(){freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
int maxn = 0;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        ray();
    #endif
   
    int n; cin >> n;
   	vector<int> a(n);
   	for (int &x : a) cin >> x;

   	stack<int> ak;
  	vector<int> l(n, -1), r(n, n), result(n+1, -1);

  	for (int i = 0; i < n; ++i){
  		while (!ak.empty() && a[ak.top()] > a[i]){
  			r[ak.top()] = i; 
  			ak.pop();
  		}

  		if (!ak.empty()) 
            if (a[i] > a[ak.top()]) l[i] = ak.top();
            else l[i] = l[ak.top()];
  		ak.push(i);
  	}

    for (int i = 0; i < n; ++i){
        int length = r[i] - l[i] - 1;
        result[length] = max(result[length], a[i]);
    }

    for (int i = n-1; i > 0; --i){
        result[i] = max(result[i], result[i+1]);
    }

    for (int i = 1; i <= n; ++i){
        cout << result[i] << ' ';
    }
    return 0;
}