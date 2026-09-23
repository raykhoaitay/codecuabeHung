#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

struct Point {
    int a, b;

    Point (){};
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].a >> a[i].b;

    vector<Point> b = a;
    sort(b.begin(), b.end(), [](const Point &aa, const Point &bb){
        if (aa.a == bb.a) return aa.b > bb.b;
        return aa.a < bb.a;
    });

    vector<int> dp;
    for (int i = 0; i < b.size(); ++i){
        auto it = lower_bound(dp.begin(), dp.end(), b[i].b);
        if (it == dp.end()) dp.push_back(b[i].b);
        else *it = b[i].b;
    }

    cout << dp.size();
    return 0;
}