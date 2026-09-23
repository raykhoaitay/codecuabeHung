// #include <bits/stdc++.h>

// #define int long long
// using namespace std;

// void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
// void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

// int mod = 1000000007;
// const int maxn = 2e5+10;
// int a[maxn];

// int calc(const int &x){
//     return x * (x-1) / 2;
// }

// int solver(){
//     int n, x, y; cin >> n >> x >> y;
//     unordered_map<int, vector<int>> mdy;
//     for (int i = 1; i <= n; ++i){
//         cin >> a[i];
//         mdy[a[i] % y].push_back(i);
//     }

//     int cow = 0;
//     for (const auto &xx : mdy){
//         int i = xx.first;
//         map<int, int> cnt;
        
//         for (int j = 0; j < mdy[i].size(); ++j){
//             cnt[a[mdy[i][j]] % x]++;
//         }

//         for (int j = 0; j < mdy[i].size(); ++j){
//             int target = a[mdy[i][j]] % x;
//             if (cow == 0){
//                 cow += calc(cnt[target]);
//             }
//             else cow += (cnt[target] * cnt[x-target]);
//         }
//     }

//     return cow;
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     #ifndef ONLINE_JUDGE
//         ray();
//     #endif

//     int t; cin >> t;
//     while (t--) cout << solver() << '\n';

//     return 0;
// }

