#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.in", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 5e4 +10;
int a[maxn], pf[maxn];

int calc(int x){
    return x * (x-1) / 2;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n; cin >> n;
    pf[0] = 0;

    vector<vector<int>> cow(7, vector<int> ());
    cow[0].push_back(0);
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pf[i] = pf[i-1] + a[i];
        cow[pf[i] % 7].push_back(i);
    }

    int maxx = 0; 
    for (int i = 0; i < 7; ++i){
        if (cow[i].size() > 1){
            int ref = cow[i][cow[i].size()-1] - cow[i][0];

            maxx = max(maxx, ref);
        }
    }

    cout << maxx << '\n';
    return 0;
}