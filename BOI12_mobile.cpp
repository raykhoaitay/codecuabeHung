#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e6+10;
double EPS = 1e-9;

int x[maxn], y[maxn];

int n, l; 
bool check(double xx){
    double left = 0;
    for (int i = 1; i <= n; ++i){
        if (xx < abs(y[i])) continue;

        double next = x[i] + sqrt(xx*xx - y[i]*y[i]);
        if (next <= left) continue;
        else {
            if (x[i] - sqrt(xx*xx - y[i]*y[i]) <= left + EPS){
                left = next;
            }
        }

        if (left >= l) return true;
    }

    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l;
    for (int i = 1; i <= n; ++i){
        cin >> x[i] >> y[i];
    }

    double L = 0.001, R = 2e9+10;
    for (int i = 0; i < 100; i++) {
        double M = L + (R - L) / 2;
        if (check(M)) R = M;
        else L = M;
    }

    cout << fixed << setprecision(3) << L;
    return 0;
}