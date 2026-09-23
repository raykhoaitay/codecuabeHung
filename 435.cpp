#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

vector<int> digit;
int dp[20][40];
int d;
int a[3];

int cnt1(int pos, int state, int tight, int start){
    if (pos == digit.size()){
        if (!start) return 0;
        return state >= 19;
    }

    if (!tight && start && dp[pos][state] != -1) return dp[pos][state];

    int limit = tight ? digit[pos] : 9; 
    int result = 0;
    for (int i = 0; i <= limit; ++i){
        int ntight = tight && (i == digit[pos]);
        int nstart = start || (i != 0);

        int nstate = state;
        if (nstart){
            if (i == d) nstate++;
            else nstate--;
        }

        result += cnt1(pos+1, nstate, ntight, nstart);
    }

    if (!tight && start){
        dp[pos][state] = result;
    }
    return result;
}

int cnt2(int pos, int state, int tight, int start){
    if (pos == digit.size()){
        if (!start) return 0;
        return state == 19;
    }

    if (!tight && start && dp[pos][state] != -1) return dp[pos][state];

    int result = 0;
    for (int i = 1; i < 3; ++i){
        int ntight = 0;
        if (tight){
            if (a[i] > digit[pos]) continue;
            else if (a[i] == digit[pos]) ntight = 1;
        }

        if (!start && i > 0 && a[i] == 0) continue;
        int nstart = start || (a[i] != 0);

        int nstate = state;
        if (nstart){
            if (i == 1) nstate++;
            else nstate--;
        }

        result += cnt2(pos+1, nstate, ntight, nstart);
    }

    if (!start){
        int ntight = 0;
        result += cnt2(pos+1, state, ntight, start);
    }

    if (!tight && start){
        dp[pos][state] = result;
    }

    return result;
}

int solver(int x){
    digit.clear();
    if (x == 0) digit.push_back(0);
    else {
        while (x){
            digit.push_back(x % 10);
            x /= 10;
        }
    }

    reverse(digit.begin(), digit.end());
    int ans1 = 0, ans2 = 0;

    for (int i = 0; i <= 9; ++i){
        d = i;
        memset(dp, -1, sizeof(dp));
        ans1 += cnt1(0, 19, 1, 0);
    }

    a[0] = 0;
    for (int i = 0; i <= 9; ++i){
        for (int j = i+1; j <= 9; ++j){
            a[1] = i;
            a[2] = j;
            memset(dp, -1, sizeof(dp));
            ans2 += cnt2(0, 19, 1, 0);
        }
    }

    return ans1 - ans2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("odometer.in", "r", stdin);
    freopen("odometer.out", "w", stdout);
    // ray();
    int x, y; cin >> x >> y;    
    cout << solver(y) - solver(x-1);

    return 0;
}