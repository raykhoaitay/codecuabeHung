// #include <bits/stdc++.h>

// #define int long long
// using namespace std;

// void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
// void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

// int mod = 1000000007;
// const int maxn = 1e5+10;
// int a[maxn];
// unordered_map<int, int> cow;

// void fac(int x){
//     for (int i = 1; i * i <= x; ++i){
//         if (x % i == 0){
//             cow[i]++;
//             if (i != x/i) cow[x/i]++;
//         }
//     }
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     #ifndef ONLINE_JUDGE
//         ray();
//     #endif

//     int n; cin >> n;
//     for (int i = 1; i <= n; ++i){
//         cin >> a[i];
//     }

//     for (int i = 1; i <= n; ++i){
//         fac(a[i]);
//     }

//     int maxx = -1;
//     for (const auto&x : cow){
//         if (x.second == n || x.second == n-1){
//             maxx = max(maxx, x.first);
//         }
//     }

//     cout << maxx;
//     return 0;
// }

#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
int a[maxn], pf[maxn], sf[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    pf[0] = sf[n+1] = 0;
    for (int i = 1; i <= n; ++i){
        pf[i] = __gcd(pf[i-1], a[i]);
        sf[n-i+1] = __gcd(sf[n-i+2], a[n-i+1]);
    }

    int maxx = -1;
    for (int i = 1; i <= n; ++i){
        maxx = max(maxx, __gcd(pf[i-1], sf[i+1]));
    }

    cout << maxx << '\n';
    return 0;
}