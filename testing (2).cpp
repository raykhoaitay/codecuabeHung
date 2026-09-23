// // // // // #include <bits/stdc++.h>

// // // // // #define int long long
// // // // // using namespace std;

// // // // // void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
// // // // // void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

// // // // // int mod = 1000000007;
// // // // // const int maxn = 1010;

// // // // // signed main() {
// // // // //     ios_base::sync_with_stdio(false);
// // // // //     cin.tie(nullptr);

// // // // //     int n; cin >> n;
// // // // //     vector<int> o, e;

// // // // //     int x; 
// // // // //     for (int i = 0; i < n; ++i){
// // // // //         cin >> x;
// // // // //         if (x % 2){
// // // // //             o.push_back(x);
// // // // //         }
// // // // //         else e.push_back(x);
// // // // //     }

// // // // //     int stt = 0, cow = 0;
// // // // //     int odd = o.size(), even = e.size();
// // // // //     if (odd == 0){
// // // // //         if (even == 0)
// // // // //         cout << 0 << '\n';

// // // // //         else cout << 1;
// // // // //     }

// // // // //     int usedO = 0, usedE = 0;

// // // // //     while (usedO < odd){
// // // // //         if (stt == 0){
// // // // //             if (even - usedE > 0){
// // // // //                 usedE++;
// // // // //                 cow++;
// // // // //             }
// // // // //             else {
// // // // //                 if (odd - usedO >= 2){
// // // // //                     usedO += 2;
// // // // //                     cow++;
// // // // //                 }
// // // // //                 else if (odd - usedO == 1){
// // // // //                     usedO++;
// // // // //                 }
// // // // //             }
// // // // //         }
// // // // //         else {
// // // // //             if (odd - usedO > 0){
// // // // //                 usedO++;
// // // // //                 cow++;
// // // // //             }
// // // // //         }
// // // // //         stt = 1 - stt;
// // // // //     }

// // // // //     if (even - usedE > 0){
// // // // //         if (!stt){
// // // // //             cow++;
// // // // //         }
// // // // //     }

// // // // //     cout << cow;
// // // // //     return 0;
// // // // // }

// // // // #include <bits/stdc++.h>

// // // // #define int long long
// // // // using namespace std;

// // // // void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
// // // // void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

// // // // int mod = 1000000007;
// // // // const int maxn = 0;

// // // // signed main() {
// // // //     ios_base::sync_with_stdio(false);
// // // //     cin.tie(nullptr);

    
// // // //     // #ifndef ONLINE_JUDGE
// // // //     //     ray();
// // // //     // #endif

// // // //     // freopen(".in", "r", stdin);
// // // //     // freopen(".out", "w", stdout);

// // // //     int n; cin >> n;
// // // //     int x;
// // // //     int o = 0, e = 0;
// // // //     for (int i = 0; i < n; ++i){
// // // //         cin >> x;
// // // //         if (x % 2) o++;
// // // //         else e++;
// // // //     }

// // // //     if (o == 0){
// // // //         if (e > 0) cout << 1;
// // // //         else cout << 0;
// // // //         return 0;
// // // //     }

// // // //     int uo = 0, ue = 0;
// // // //     int stt = 0, cow = 0;
// // // //     while (uo < o){
// // // //         if (!stt){
// // // //             if (e - ue > 0){
// // // //                 ue++;
// // // //                 cow++;
// // // //             }
// // // //             else {
// // // //                 if (o - uo > 1){
// // // //                     uo += 2;
// // // //                     cow++;
// // // //                 }
// // // //                 else if (o - uo == 1){
// // // //                     cow--;
// // // //                     uo++;
// // // //                 }
// // // //             }
// // // //         }
// // // //         else {
// // // //             if (o - uo > 0){
// // // //                 uo++;
// // // //                 cow++;
// // // //             }
// // // //         }
// // // //         stt = 1 - stt;
// // // //     }

// // // //     if (e - ue > 0){
// // // //         if (!stt) cow++;
// // // //     }

// // // //     cout << cow;
// // // //     return 0;
// // // // }

// // // #include <bits/stdc++.h>

// // // #define int long long
// // // using namespace std;

// // // void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
// // // void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

// // // int mod = 1000000007;
// // // const int maxn = 0;

// // // signed main() {
// // //     ios_base::sync_with_stdio(false);
// // //     cin.tie(nullptr);

// // //     #ifndef ONLINE_JUDGE
// // //         ray();
// // //     #endif

// // //     int n; cin >> n;
// // //     if (n % 2 == 0 && n > 2) cout << "YES\n";
// // //     else cout << "NO\n";

// // //     return 0;
// // // }

// // #include <bits/stdc++.h>

// // #define int long long
// // using namespace std;

// // void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
// // void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

// // int mod = 1000000007;
// // const int maxn = 0;

// // signed main() {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     #ifndef ONLINE_JUDGE
// //         ray();
// //     #endif

// //     int g, n; cin >> g >> n;
// //     unordered_map<int, int> cow;
// //     for (int i = 0; i < g; ++i){
// //         int trash, ok;
// //         cin >> trash >> trash >> ok;
// //         cow[ok]++;
// //     }

// //     for (const auto &x : cow) cout << x.first << ' ' << x.second << '\n';

// //     return 0;
// // }

// #include <bits/stdc++.h>

// #define int long long
// using namespace std;

// void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
// void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

// int mod = 1000000007;
// const int maxn = 0;

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     #ifndef ONLINE_JUDGE
//         ray();
//     #endif

//     cout << -4 / 2;

//     return 0;
// }

#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    cout << -2 % 10;

    return 0;
}