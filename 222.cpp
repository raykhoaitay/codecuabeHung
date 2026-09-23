#include <bits/stdc++.h>
#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout); }
void ray(string inp = "i.inp", string out = "o.out") {freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}

int mod = 1000000007;
int n, l, r;

int length(int x){
    int st, en;

    if (l % x == 0) st = l/x;
    else st = (l/x) + 1;

    en = r / x;

    if (st > en) return 0;
    return en - st + 1; 
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        ray();
    #endif
   
    cin >> n >> l >> r;
    vector<int> a;
    unordered_map<int, int> cow;
    int temp;

    for (int i = 0; i < n; ++i){
        cin >> temp;
        if (cow[temp] == 0){
            a.push_back(temp);
            cow[temp]++;
        }
    }

    n = a.size();
    int result = 0;
    for (int mask = 1; mask < (1 << n); ++mask){
        int target = 1;
        for (int i = 0; i < n; ++i){
            if (mask & (1 << i)) {
                target *= a[i];
            };
        }

        if (__builtin_popcount(mask) % 2 != 0) result += length(target);
        else result -= length(target);
    }

    cout << result;
    return 0;
}