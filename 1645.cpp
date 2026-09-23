// Ver A

// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout); }
// void ray(string inp = "i.inp", string out = "o.out") {freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}

// int mod = 1000000007;

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     #ifndef ONLINE_JUDGE
//         ray();
//     #endif
   
//     int n; cin >> n;
//     vector<int> a(n), res(n, 0);
//     for (int i = 0; i < n; ++i) cin >> a[i];

//     stack<int> sk;
//     for (int i = n - 1; i > -1; --i){
//         if (sk.empty()){
//             sk.push(i);
//             continue;
//         }

//         int x = sk.top();
//         while (a[i] < a[x]){
//             res[x] = i+1;
//             sk.pop();
//             if (!sk.empty()) x = sk.top();
//             else break;
//         }
//         sk.push(i);
//     }

//     for (int i = 0; i < n; ++i) cout << res[i] << ' ';
//     return 0;
// }

// Ver B
#include <bits/stdc++.h>
#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout); }
void ray(string inp = "i.inp", string out = "o.out") {freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}

int mod = 1000000007;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        ray();
    #endif
   
    int n; cin >> n;
    stack<int> sk;
    vector<int> a(n), res(n, 0);

    for (int i = 0; i < n; ++i){
        cin >> a[i];

        if (sk.empty()){
            sk.push(i);
            continue;
        }

        int x = sk.top();
        while (a[i] <= a[x]){
            sk.pop();
            if (sk.empty()) break;
            else x = sk.top();
        }

        if (!sk.empty()) res[i] = sk.top() + 1;
        sk.push(i);
    }

    for (int i = 0; i < n; ++i){
        cout << res[i] << ' ';
    }
    return 0;
}