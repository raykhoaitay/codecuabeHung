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

    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    int n; cin >> n;
    unordered_map<string, int> cow = {
        {"Bessie", 0}, 
        {"Elsie", 0}, 
        {"Daisy", 0}, 
        {"Gertie", 0}, 
        {"Annabelle", 0}, 
        {"Maggie", 0}, 
        {"Henrietta", 0}
    };

    string s; int x;
    for (int i = 0; i < n; ++i){
        cin >> s >> x;
        cow[s] += x;
    }

    map<int, int> freq;
    for (const auto &x : cow){
        freq[x.second]++;
    }

    int i = 0;
    for (const auto &x : freq){
        if (i == 1){
            if (x.second == 1){
                for (const auto &y : cow){
                    if (y.second == x.first){
                        cout << y.first << '\n';
                        return 0;
                    }
                }
            }
        }
        i++;
    }

    cout << "Tie\n";
    return 0;
}