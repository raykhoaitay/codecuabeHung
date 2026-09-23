#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("billboard.in", "r", stdin);
    // freopen("billboard.out", "w", stdout);

    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x2 >> y1 >> x1 >> y2 >> x4 >> y3 >> x3 >> y4;

    int h = x1 - x2, w = y2 - y1;
    if (x3 >= x1 && x4 <= x2){
        if (y3 <= y1 && y4 <= y2){
            w = min(y2 - y1, y2 - y4);
        }
        else if (y1 <= y3 && y2 <= y4){
            w = min(y3 - y1, y2 - y1);
        }
    }
    else if (y3 <= y1 && y2 <= y4){
        if (x1 >= x3 && x2 >= x4){
            h = min(x1 - x2, x1 - x3);
        }
        else if (x3 >= x1 && x4 >= x2){
            h = min(x4 - x2, x1 - x2);
        }
    }

    if (h < 0) h = 0;
    if (w < 0) w = 0;

    cout << w * h << '\n';

    return 0;
}