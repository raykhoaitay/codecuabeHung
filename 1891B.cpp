// #include <bits/stdc++.h>

// #define int long long
// using namespace std;

// void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
// void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

// int mod = 1000000007;
// const int maxn = 1e5+10;
// int a[maxn], x[maxn];

// struct El {
//     int val, idx;

//     El(){};
//     El (int val, int idx): val(val), idx(idx) {};

//     bool operator <(const El &other) const {
//         return val < other.val;
//     }
// };

// int count(int x){
//     int cow = 0;
//     while (x % 2 == 0){
//         cow++;
//         x /= 2;
//     }

//     return cow;
// }

// void solver(){
//     priority_queue<El> pq;

//     int n, q; cin >> n >> q;
//     for (int i = 1; i <= n; ++i){
//         cin >> a[i];
//         int c = count(a[i]);
//         if (c == 0) continue;

//         pq.push({c, i});
//     }

//     for (int i = 1; i <= q; ++i) cin >> x[i];

//     stack<El> st;
//     for (int i = 1; i <= q; ++i){
//         if (pq.empty()) break;
//         El f = pq.top();
//         while (x[i] <= f.val){
//             pq.pop();
//             a[f.idx] += (1 << (x[i] - 1));
//             st.push({x[i]-1, f.idx});

//             if (pq.empty()) break;
//             f = pq.top();
//         }

//         while (!st.empty()){
//             pq.push(st.top());
//             st.pop();
//         }
//     }

//     for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
//     cout << endl;
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     #ifndef ONLINE_JUDGE
//         ray();
//     #endif

//     int t; cin >> t;
//     while (t--) solver();

//     return 0;
// }


#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
int a[maxn], p[maxn];

int cnt(int x){
    int cow = 0;
    while (x % 2 == 0){
        cow++;
        x /= 2;
    }

    return cow;
}

void solver(){
    int n, q; cin >> n >> q;
    int prx = -1e9;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        p[i] = cnt(a[i]);
        prx = max(prx, p[i]);
    }

    int x;
    for (int i = 1; i <= q; ++i){
        cin >> x;
        if (x > prx) continue;

        for (int j = 1; j <= n; ++j){
            if (p[j] < x) continue;
            p[j] = x - 1;
            a[j] += (1 << (x - 1));
        }

        prx = x - 1;
    }

    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--) solver();

    return 0;
}