#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

struct Point {
    int xa, xb;

    Point (){};
};

Point a[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("pcb.in", "r", stdin);
    freopen("pcb.out", "w", stdout);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].xa >> a[i].xb;
    }

    sort(a+1, a+1+n, [](const Point &aa, const Point &bb){
        return (aa.xa < bb.xa);
    });

    vector<int> dp;
    for (int i = n; i; --i){
        auto it = upper_bound(dp.begin(), dp.end(), a[i].xb);
        if (it == dp.end()) dp.push_back(a[i].xb);
        else *it = a[i].xb;
    }

    cout << dp.size();

    return 0;
}