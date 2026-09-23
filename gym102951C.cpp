#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

struct Element {
    int x, y; 

    Element(){};
};

int lct[maxn];
Element ok[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    int temp;

    for (int i = 1; i <= n; ++i){
        cin >> temp;
        lct[temp] = i;
    }

    for (int i = 1; i <= n; ++i){
        cin >> temp;

        ok[i].x = lct[temp];
        ok[i].y = i;
    }

    sort(ok+1, ok+1+n, [](const Element &aa, const Element &bb){
        return aa.x < bb.x;
    });

    vector<int> dp;
    for (int i = 1; i <= n; ++i){
        auto it = lower_bound(dp.begin(), dp.end(), ok[i].y);
        if (it == dp.end()) dp.push_back(ok[i].y);
        else *it = ok[i].y;
    }

    cout << dp.size() << '\n';
    return 0;
}