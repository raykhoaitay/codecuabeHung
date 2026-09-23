#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

int solver(){
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
        
    string aa = "";
    int limit;
    if (n >= m){
        limit = 2;
    }
    else if (n < m){
        limit = 7;
    }

    for (int _ = 0; _ < limit; ++_){
        if (_ == 0) aa += a;
        else aa += aa;
        if (aa.size() < m) continue;
        for (int i = 0; i < aa.size(); ++i){
            if (aa[i] == b[0]){
                int c = 0;
                for (int j = 1; j < m; ++j){
                    if (aa[i+j] != b[j]){
                        c = 1;
                        break;
                    }
                }

                if (c == 0) return (_);
            }
        }
    }

    return -1;
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