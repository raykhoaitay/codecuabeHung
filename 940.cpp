// #include <bits/stdc++.h>

// #define int long long
// using namespace std;

// void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
// void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

// int mod = 1000000007;
// const int maxn = 110;

// int par[maxn], sz[maxn];

// int find(int u){
//     if (u == par[u]) return u;
//     return par[u] = find(par[u]);
// }

// void un(int a, int b){
//     a = find(a);
//     b = find(b);

//     sz[a] += sz[b];
//     par[b] = a;
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     ray();
//     int n; cin >> n;
//     for (int i = 1; i <= n; ++i){
//         par[i] = i;
//         sz[i] = 1;
//     }

//     for (int i = 1; i < n; ++i){
//         int x, y; cin >> x >> y;
//         un(y, x);
//     }

//     for (int i = 1; i <= n; ++i){
//         cout << sz[i] << ' ';
//     }

//     cout << -1 << '\n';
//     return 0;
// }

#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 110;
int ou[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    int n; cin >> n;
    int x, y;
    memset(ou, 0, sizeof(ou));
    for (int i = 1; i < n; ++i){
        cin >> x >> y;
        ou[x]++;
    }

    int guard = 0;
    for (int i = 1; i <= n; ++i){
        if (ou[i] == 0){
            if (guard == 0){
                guard = i;
            }
            else {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << guard << '\n';
    return 0;
}