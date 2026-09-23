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
    while (n--){
    	int t, h, u; cin >> t >> h >> u;

    	int op1 = min(t, u);
    	int result = (op1) * 4;

    	t -= op1;
    	u -= op1;

    	int t2 = t/2;
    	int op2 = min(t2, h);
    	result += (op2 * 7);
    	t -= (op2*2);
    	h -= op2;

    	if (t >= 2){
    		int op3 = t;
    		result += 2*op3 + 1; 
    		t -= op3;
    	}

    	if (t == 1 && h >= 1){
    		h--;
    		t--;
    		result += 5;
    	}

    	cout << result + (t + u + h) * 3 << '\n';
    }
    return 0;
}