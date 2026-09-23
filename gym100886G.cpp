#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

pair<int, string> dp[20][2][2][2];
bool vst[20][2][2][2];
vector<int> digia, digib;

pair<int, string> cnt1(int pos, int tia, int tib, int st){
    if (pos == digib.size()){
        if (!st) return {0, ""};
        return {1, ""};
    }

    if (vst[pos][tia][tib][st]) return dp[pos][tia][tib][st];

    int maxx = 0;
    string res;
    int lima = (tia) ? digia[pos] : 0;
    int limb = (tib) ? digib[pos] : 9;

    for (int i = lima; i <= limb; ++i){
        int nst = st || (i > 0);
        int ntib = tib && (i == digib[pos]);
        int ntia = tia;

        if (nst){
            if (i > digia[pos]) ntia = 0;
        }

        pair<int, string> temp = cnt1(pos+1, ntia, ntib, nst);
        if (nst){
            if (maxx < temp.first * i){
                maxx = temp.first * i;
                res = to_string(i) + temp.second;
            }
        }
        else {
            if (maxx <temp.first){
                maxx = temp.first;
                res = temp.second;
            }
        }
    }

    dp[pos][tia][tib][st].first = maxx;
    dp[pos][tia][tib][st].second = res;
    vst[pos][tia][tib][st] = 1;
    return dp[pos][tia][tib][st];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int a, b; cin >> a >> b;
    while (a){
        digia.push_back(a % 10);
        a /= 10;
    }
    while (b){
        digib.push_back(b % 10);
        b /= 10;
    }

    while (digia.size() < digib.size()){
        digia.push_back(0);
    }

    reverse(digia.begin(), digia.end());
    reverse(digib.begin(), digib.end());

    memset(vst, 0, sizeof(vst));
    pair<int, string> ans = cnt1(0, 1, 1, 0);
    cout << ans.second;
    return 0;
}