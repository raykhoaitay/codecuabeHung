// #include <bits/stdc++.h>

// #define int long long
// using namespace std;

// void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
// void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

// int mod = 1000000007;
// const int maxn = 150;
// int a[maxn], diff[maxn];

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     #ifndef ONLINE_JUDGE
//         ray();
//     #endif

//     int n; cin >> n;
//     for (int i = 1; i <= 2*n; ++i){
//         cin >> a[i];
//     }

//     sort(a+1, a+2*n);

//     int summ = 0;
//     for (int i = 2; i <= 2*n; ++i){
//         diff[i] = a[i] - a[i-1];
//         summ += diff[i];
//     }

//     int temp1 = diff[2] + diff[3];
//     temp1 += (2*n > 4) ? diff[4] : 0;
//     int maxx = max(temp1, diff[2*n-1] + diff[2*n]);
//     cout << summ - maxx;

//     return 0;
// }

#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 55*2;
int a[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    n *= 2;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    sort(a, a+n+1);
    int minn = 1e9;
    for (int i = 1; i <= n; i += 2){
        for (int j = i+1; j <= n; j += 2){
            int cost = 0;
            for (int k = 2; k < i; k += 2){
                cost += a[k] - a[k-1];
            }
            for (int k = i + 2; k < j; k += 2){
                cost += a[k] - a[k-1];
            }
            for (int k = j + 2; k <= n; k += 2){
                cost += a[k] - a[k-1];
            }
            minn = min(minn, cost);
        }
    }

    cout << minn;
    return 0;
}