#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

struct Number {
    int v, i;

    Number (){};
    Number (int v, int i): v(v), i(i) {};
};

int solver(){
    int a, b, x; cin >> a >> b >> x;

    vector<Number> da, db;

    int cow = 0, check = 0;
    while (true){
        da.push_back({a, cow});
        if (check) break;
        a /= x;
        cow++;
        if (a == 0) check = 1;
    }

    cow = 0;
    check = 0;
    while (true){
        db.push_back({b, cow});
        if (check) break;
        b /= x;
        cow++;
        if (b == 0) check = 1;
    }

    int minn = 1e9;
    for (const auto &x : da){
        for (const auto &y : db){
            minn = min(minn, abs(x.v - y.v) + x.i + y.i);
        }
    }

    return minn;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--){
        cout << solver() << '\n';
    }

    return 0;
}