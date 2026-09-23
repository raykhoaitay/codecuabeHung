#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 15;

int a[maxn][maxn];

int solver(){
    char c;
    int result = 0;
    for (int i = 1; i < 11; ++i){
        for (int j = 1; j < 11; ++j){
            cin >> c;
            if (c == 'X') a[i][j] = 1;
            else a[i][j] = 0;

            if (a[i][j] == 1){
                result += min(min(i, 10-i+1), min(j, 10-j+1));
            }
        }
    }

    return result;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--){
        cout << solver() << '\n';
    }

    return 0;
}