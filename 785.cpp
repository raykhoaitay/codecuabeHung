#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e6+10;
int a[110], cow[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n; cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        cow[a[i]]++;
    }

    int target = -1, start = -1;
    a[n+1] = 1e9;
    for (int i = 1; i <= n; ++i){
        if (a[i] > a[i-1] && a[i] > a[i+1]){
            target = a[i];
            start = a[i+1];
        }
        else if (a[i] < a[i-1] && a[i] < a[i+1]){
            target = a[i];
            start = a[i-1];
        }
    }

    int result = 0;
    if (start < target){
        for (int i = start; i < target; ++i){
            if (cow[i] > 0) result++;
        }
    }
    else if (target == start){
        cout << 0 << endl;
        return 0;
    }
    else {
        for (int i = start; i > target; --i){
            if (cow[i] > 0) result++;
        }
    }

    cout << result;
    return 0;
}