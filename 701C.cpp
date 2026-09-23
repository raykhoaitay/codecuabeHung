// #include <bits/stdc++.h>

// #define int long long
// using namespace std;

// void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
// void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

// int mod = 1000000007;
// const int maxn = 1e5+10;
// char a[maxn];
// int n;
// vector<int> wt;

// bool check(int len){
//     int cow0 = 0, cow[150];
//     memset(cow, 0, sizeof(cow));

//     for (int i = 1; i <= len; ++i) cow[a[i]]++;
//     for (const auto x : wt) if (cow[x] == 0) cow0++;

//     if (cow0 == 0) return true;

//     for (int i = 2; i + len-1 <= n; ++i){
//         cow[a[i-1]]--;
//         if (cow[a[i-1]] == 0) cow0++;
//         cow[a[i+len-1]]++;
//         if (cow[a[i+len-1]] == 1) cow0--;

//         if (cow0 == 0) return true;
//     }

//     return false;
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     #ifndef ONLINE_JUDGE
//         ray();
//     #endif

//     cin >> n;

//     int cow[150];
//     memset(cow, 0, sizeof(cow));

//     for (int i = 1; i <= n; ++i){
//         cin >> a[i];
//         cow[a[i]]++;
//         if (cow[a[i]] == 1) wt.push_back(a[i]);
//     }

//     int l = 1, r = n;
//     while (l < r){
//         int mid = (l + r)/2;

//         bool curr = check(mid);
//         if (curr) r = mid;
//         else l = mid+1;
//     }

//     cout << l;

//     return 0;
// }

#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
char a[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    int cow[300];
    memset(cow, 0, sizeof(cow));
    int wt=0;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        cow[a[i]]++;

        if (cow[a[i]] == 1) wt++;
    }

    memset(cow, 0, sizeof(cow));
    int i = 1, j = 1, cow0 = wt;
    int minn = 1e9;
    while (j <= n){
        cow[a[j]]++;
        if (cow[a[j]] == 1){
            cow0--;
        }

        while (cow0 == 0){
            minn = min(minn, j - i + 1);
            cow[a[i]]--;
            if (cow[a[i]] == 0) cow0++;
            i++;
        }

        j++;
    }

    cout << minn << '\n';
    return 0;
}