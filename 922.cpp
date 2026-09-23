#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
int a[maxn], bottom[maxn], n;
vector<int> vst[maxn];

int check() {
    int last = 0, rleft = 1, sz = 0;

    for (int i = 1; i <= n; ++i) {
        if (a[i] < last) return i - 1;

        int target = lower_bound(bottom + rleft, bottom + sz + 1, a[i]) - bottom;

        if (target > sz) {
            sz++;
            bottom[sz] = a[i];
            vst[sz].push_back(a[i]);
        } else {
            if (vst[target].back() < a[i]) {
                while (rleft < target) {
                    while (!vst[rleft].empty()) {
                        last = max(last, vst[rleft].back());
                        vst[rleft].pop_back();
                    }
                    rleft++;
                }
                while (!vst[target].empty() && vst[target].back() < a[i]) {
                    last = max(last, vst[target].back());
                    vst[target].pop_back();
                }
            }
            vst[target].push_back(a[i]);
        }
    }

    return n;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << check();

    return 0;
}