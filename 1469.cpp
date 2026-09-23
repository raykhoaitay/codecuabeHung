#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 7550;
vector<int> up[maxn];
int cnt[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        up[a[i]].push_back(i);
    }

    unordered_map<int, int> cow;
    memset(cnt, 0, sizeof(cnt));

    for (int i = 1; i <= n; ++i){
        cin >> b[i];

        for (const auto &x : up[b[i]]){
            cow[i+x]++;
        }   
    }

    for (const auto &x : cow){
        cnt[x.second]++;
    }

    return 0;
}