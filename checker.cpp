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

    int t = 100;
    
    for (int i = 1; i <= t; ++i){
        system("gen.exe > i.inp");

        system("dtmrctldl_segtree3.exe < i.inp > o.out");
        system("bf.exe < i.inp > ans.txt");

        if (system("fc o.out ans.txt > nul") != 0){
            cout << "SAI TEST " << i << "!" << endl;
            return 0;
        }

        cout << "TEST " << i << " OK." << endl;
    }

    return 0;
}