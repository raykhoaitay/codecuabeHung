#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 200;
int a[maxn];

int solver(){
    int n; cin >> n;
    int blanc = 0;
    for (int i = 1; i <= n; ++i){
        char c; cin >> c;
        if (c == '.'){
            blanc++;
            a[i] = 0;
        }
        else a[i] = 1;
    }

    int maxx = 0;
    int i = 1, j = 1, curr = 0;
    while (j <= n){
        if (a[j] == 1){
            curr = 0;
            i = j + 1;
        }
        else curr++;

        maxx = max(maxx, curr);
        j++;
    }
    
    if (maxx >= 3) return 2;
    else return blanc;
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