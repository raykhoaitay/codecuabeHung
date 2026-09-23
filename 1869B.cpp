#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5;

struct Point {
    int x, y, idx; 

    Point (){};
};

int leg(const Point &fi, const Point &se){
    return abs(se.x - fi.x) + abs(se.y - fi.y);
}

int solver(){
    int n, k, l, r; cin >> n >> k >> l >> r;
    vector<Point> a(n+1, Point());

    for (int i = 1; i <= n; ++i){
        cin >> a[i].x >> a[i].y;
        a[i].idx = i;
    }

    if (a[l].idx <= k && a[r].idx <= k) return 0;

    vector<int> disa, disb;

    int min1 = 1e10, min2 = 1e10;
    for (int i = 1; i <= k; ++i){
        int val1 = leg(a[l], a[i]);
        disa.push_back(val1);
        min1 = min(min1, val1);

        int val2 = leg(a[r], a[i]);
        disb.push_back(val2);
        min2 = min(min2, val2);
    }

    return min(leg(a[l], a[r]), min1 + min2);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--) cout << solver() << '\n';

    return 0;
}