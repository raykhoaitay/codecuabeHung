#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 5e5+10;
vector<int> up[maxn], down[maxn], dup;
int a[maxn], b[maxn], mup[maxn], mdown[maxn], pf[maxn], n;

int solver(int x){
    pf[0] = 0;
    int nn = down[x].size()-1;
    for (int i = 1; i <= nn; ++i){
        pf[i] = pf[i-1] + down[x][i];
    }

    int result = 0;
    for (int h = 0; h < up[x].size(); ++h){
        int bin1 = upper_bound(down[x].begin(), down[x].end(), n + 1 - up[x][h]) - down[x].begin();
        int bin2 = upper_bound(down[x].begin(), down[x].begin() + bin1, up[x][h]) - down[x].begin();
        int bin3 = upper_bound(down[x].begin() + bin1, down[x].end(), up[x][h]) - down[x].begin();

        int r1 = pf[bin2-1] - pf[0],
        r2 = (bin1 - bin2) * up[x][h],
        r3 = (n - up[x][h] + 1) * (bin3 - bin1),
        r4 = (nn - bin3 + 1) * (n + 1) - (pf[nn] - pf[bin3 - 1]);

        result += r1 + r2 + r3 + r4;
    }

    return result;
}

int calc(int x){
    return x * (x+1) /2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    memset(mup, 0, sizeof(mup));
    memset(mdown, 0, sizeof(mdown));

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i){
        cin >> b[i];
        if (mdown[b[i]] == 0){
            down[b[i]].push_back(0);
            mdown[b[i]]++;
        }

        down[b[i]].push_back(i);
    }

    for (int i = 1; i <= n; ++i){
        if (a[i] == b[i]){
            dup.push_back(i);
        }

        if (mup[a[i]] == 0){
            mup[a[i]]++;
        }
        up[a[i]].push_back(i);
    }

    int result = 0;
    for (int i = 1; i <= maxn; ++i){
        if (mup[i] == 1 && mdown[i] == 1){
            result += solver(i);
        }
    }

    for (auto x : dup){
        result += calc(x-1);
        result += calc(n-x);
    }

    cout << result;

    return 0;
}