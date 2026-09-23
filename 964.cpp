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

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int n; string s; cin >> n >> s;
    unordered_map<string, int> cow;

    for (int _ = 1; _ <= n; ++_){
        int check = 0;
        for (int i = 0; i + _ <= n; ++i){
            string temp = s.substr(i, _);
            cow[temp]++;
            if (cow[temp] >= 2){
                check = 1;
                break;
            }
        }
        if (check) continue;
        else {
            cout << _;
            break;
        }
    }

    return 0;
}