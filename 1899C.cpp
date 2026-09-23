#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;
int a[maxn];

bool check(const int &a, const int &b){
    return (abs(a) % 2 == 1 && abs(b) % 2 == 0) || (abs(a) % 2 == 0 && abs(b) % 2 == 1);
}

int solver(){
    int n; cin >> n;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    int i = 1, j = 1;
    int sum = 0;
    int maxx = -1e9;
    while (j <= n){
        while (j < n && check(a[j], a[j+1])){
            j++;
        }

        int meh = a[i];
        int msf = meh;
        for (int ii = i+1; ii <= j; ++ii){
            meh = max(meh + a[ii], a[ii]);
            msf = max(msf, meh);
        }

        j++;
        i = j;
        maxx = max(maxx, msf);
    }

    return maxx;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--) cout << solver() << '\n';

    return 0;
}