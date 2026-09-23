#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

vector<int> a;
int n;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    cin >> n;
    a.assign(n, 0);
    unordered_map<int, int> cow, BIT;

    for (int i = 0; i < n; ++i){
        cin >> a[i];
        if (!cow[a[i]]) cow[a[i]] = i+1;

        BIT[a[i]] = max(BIT[a[i]], BIT[a[i]-1]+1);
    }   

    int maxx = 0, idx = 0;
    for (const auto &x : BIT){
        if (x.second > maxx){
            maxx = x.second;
            idx = x.first;
        }
    }

    cout << maxx << '\n';
    vector<int> ok;
    int target = idx;
    for (int i = n-1; i+1; --i){
        if (a[i] == target){
            ok.push_back(i+1);
            target--;
            if (target == idx - maxx) break;
        }
    }

    reverse(ok.begin(), ok.end());
    for (int x : ok) cout << x << ' ';
    return 0;
}