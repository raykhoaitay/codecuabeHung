#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {
    string inp = name + ".inp";
    string out = name + ".out";
    freopen(inp.c_str(), "r", stdin);
    freopen(out.c_str(), "w", stdout);
}

void ray() {
    freopen("i.inp", "r", stdin);
    freopen("o.out", "w", stdout);
}

int mod = 1000000007;
int maxn = 0;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        // ray();
    #endif

    string s;
    int check = 0;
    while (check == 0){
        getline(cin, s);
        if (s != "Is it rated?"){
            check = 1;
        }
        else {
            cout << "NO" << endl;
        }9
    }

    return 0;
}