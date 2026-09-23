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
   
    string s; cin >> s;
    int n = s.size();
    stack<int> st;

    for (int i = 0; i < n; ++i){
    	if (s[i] >= '0' && s[i] <= '9'){
    		st.push(s[i] - '0');
    	}
		else {
			int x = st.top();
			st.pop();
			int y = st.top();
			st.pop();
			if (s[i] == '+') st.push(x+y);
			else if (s[i] == '*') st.push(x*y);
		}
    }
    cout << st.top();
    return 0;
}