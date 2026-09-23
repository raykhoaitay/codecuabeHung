#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

vector<int> digit;
int dp[20][2][2];

int magic(int pos){
    int result = 0;
    for (int i = pos + 1; i < digit.size(); ++i){
        result = result * 10 + digit[i];
    }

    return result+1;
}

int cnt(int pos, int tight, int start){
    if (pos == digit.size()){
        return 0;
    }
    if (dp[pos][tight][start] != -1) return dp[pos][tight][start];

    int result = 0;
    int limit = tight ? digit[pos] : 9;
    for (int i = 0; i <= limit; ++i){
        int nstart = start || (i > 0);
        int ntight = tight && (i == digit[pos]);

        int f;
        if (!ntight){
            int ex = digit.size() - pos - 1;
            int uk = 1;
            for (int _ = 1; _ <= ex; ++_){
                uk *= 10;
            }
            f = uk * i;
        }
        else {
            f = magic(pos) * i;
        }
        result += f + cnt(pos+1, ntight, nstart);
    }

    return dp[pos][tight][start] = result;
}

int solver(int x){
    digit.clear();
    if (x == 0) digit.push_back(0);
    else while (x){
        digit.push_back(x % 10);
        x /= 10;
    }

    reverse(digit.begin(), digit.end());

    memset(dp, -1, sizeof(dp));
    return cnt(0, 1, 0);
}

int tc(){
    int a, b; cin >> a >> b;
    return solver(b) - solver(a-1); 
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;

    while (t--) cout << tc() << '\n';

    return 0;
} 