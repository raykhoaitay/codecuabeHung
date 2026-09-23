#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

int a, b, d, k;
vector<int> digit;
int dp[20][20][2][2];

int cnt(int pos, int cow, int tight, int start){
    if (cow > k) return 0;
    if (pos == digit.size()) return cow == k;

    if (dp[pos][cow][tight][start] != -1) return dp[pos][cow][tight][start];

    int limit = (tight) ? digit[pos] : 9;
    
    int result = 0;
    for (int i = 0; i <= limit; ++i){
        int ntight = tight && (i == digit[pos]);
        int nstart = start || (i != 0);
        int ncow = cow;

        if (i == d && nstart) ncow++;

        result += cnt(pos+1, ncow, ntight, nstart);
    }

    return dp[pos][cow][tight][start] = result;
}

int solver(int x){
    digit.clear();

    if (x == 0) digit.push_back(0);
    else {
        while (x > 0){
            digit.push_back(x % 10);
            x /= 10;
        }
    }

    reverse(digit.begin(), digit.end());
    memset(dp, -1, sizeof(dp));

    // pos, cnt, tight, start
    return cnt(0, 0, 1, 0);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    cin >> a >> b >> d >> k;

    cout << solver(b) - solver(a-1);

    return 0;
}