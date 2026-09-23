#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
int a[maxn], pf[maxn];
unordered_map<int, int> cow;

int calc(int x){
    return x * (x - 1) / 2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;
        pf[0] = 0;
        cow.clear();
        cow[0] = 1;

        for (int i = 1; i <= n; ++i){
            a[i] = s[i-1] - '0';
            pf[i] = pf[i-1] + a[i];
            cow[(pf[i] - i)]++;
        }

        int result = 0;
        for (const auto &x : cow){
            result += calc(x.second);
        }

        cout << result << '\n';
    }

    return 0;
}