#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
int a[maxn];

bool solver(){
    int n; cin >> n;
    unordered_map<int, int> cow;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        cow[a[i]]++;
    }

    int cnt = 0;
    vector<int> oe;
    for (const auto &x : cow){
        cnt++;
        oe.push_back(x.second);
    }

    if (cnt > 2) return false;
    if (cnt == 1) return true;
    return (min(oe[1], oe[0]) == (n/2));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--){
        if (solver()) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}