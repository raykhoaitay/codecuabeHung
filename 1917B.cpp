#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

int solver(){
    int n; cin >> n;
    string s; cin >> s;
    int first[30];

    int result = 0;
    memset(first, 0, sizeof(first));
    for (int i = 0; i < n; ++i){
        if (first[s[i]-'a'] == 0){
            first[s[i]-'a']  = i+1;
            result += n - i;
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