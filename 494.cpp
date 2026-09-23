#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 22;

struct Cow {
    int h, w, s;

    Cow (){};
} a[maxn];

struct St {
    int usb, h, w, s, mins;

    St(){
        usb = h = w = s = mins = 0;
    }
} dp[(1 << maxn)];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ray();
    int n, h; cin >> n >> h;
    for (int i = 0; i < n; ++i) cin >> a[i].h >> a[i].w >> a[i].s;

    int maxx = -1;
    sort(a, a+n, [](const Cow &aa, const Cow &bb){
        if (aa.s == bb.s){
            if (aa.w == bb.w) return aa.h > bb.h;
            return aa.w < bb.w;
        }
        return aa.s < bb.s;
    });

    dp[0] = St();
    dp[0].usb = 1;
    dp[0].w = 0;
    dp[0].s = 1e15;
    dp[0].mins = 1e15;

    for (int mask = 0; mask < (1 << n); ++mask){
        if (!dp[mask].usb) continue;

        int msb = 63 - __builtin_clzll(mask);
        int add = 1;
        if (mask == 0) add = 0;
        for (int i = msb+add; i < n; ++i){
            int nmask = mask | (1 << i);

            dp[nmask].h = dp[mask].h + a[i].h;
            dp[nmask].w = dp[mask].w + a[i].w;
            dp[nmask].s = a[i].s - dp[mask].w; 

            if (dp[nmask].s >= 0) dp[nmask].usb = 1;
            else continue;

            dp[nmask].mins = min(dp[nmask].s, dp[mask].mins);
            if (dp[nmask].h >= h){
                maxx = max(maxx, dp[nmask].mins);
            }
        }
    }
    
    cout << maxx;

    return 0;
}