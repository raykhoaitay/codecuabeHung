#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
int a[maxn], ml[maxn], mr[maxn];
int solver(){
    int n; cin >> n;
    memset(ml, 0, sizeof(ml));
    memset(mr, 0, sizeof(mr));

    cin >> a[1];
    ml[1] = a[1] + 1;

    for (int i = 2; i <= n; ++i){
        cin >> a[i];

        ml[i] = max(ml[i-1], a[i] + i);
    }

    mr[n] = a[n] - n;
    for (int i = n-1; i > 0; --i){
        mr[i] = max(mr[i+1], a[i] - i);
    }

    int result = -1e9;
    for (int i = 2; i < n; ++i){
        result = max(result, ml[i-1] + a[i] + mr[i+1]);
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