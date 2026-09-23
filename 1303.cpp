// #include <bits/stdc++.h>

// #define int long long
// using namespace std;

// void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
// void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

// int mod = 1000000007;
// const int maxn = 0;

// struct Point {
//     int x, y, t;

//     Point (){};
// };

// struct Store {
//     int val, type, idx; 

//     Store (){};
//     Store (int xx, int yy, int tt): val(xx), type(yy), idx(tt) {};
// };

// bool check(const Point &gg, const Point &nn, int c){
//     if (c == 1) return (gg.x >= nn.x) && (gg.y >= nn.y); 
//     if (c == 2) return (gg.x >= nn.x) && (gg.y <= nn.y);
//     if (c == 3) return (gg.x <= nn.x) && (gg.y <= nn.y);
//     if (c == 4) return (gg.x <= nn.x) && (gg.y >= nn.y);
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     #ifndef ONLINE_JUDGE
//         ray();
//     #endif

//     int g, n; cin >> g >> n;
//     vector<Point> G(g+1, Point()), N(n+1, Point());
//     vector<Store> temp;
    
//     int x, y, t;
//     for (int i = 1; i <= g; ++i){
//         cin >> x >> y >> t;
//         G[i].x = x, G[i].y = y, G[i].t = t;

//         temp.emplace_back(t - x - y, 1, i);
//         temp.emplace_back(t - x + y, 2, i);
//         temp.emplace_back(t + x + y, 3, i);
//         temp.emplace_back(t + x - y, 4, i);
//     }

//     for (int i = 1; i <= n; ++i){
//         cin >> N[i].x >> N[i].y >> N[i].t;
//     }

//     sort(temp.begin(), temp.end(), [](const auto &x, const auto &y){
//         if (x.val != y.val) return x.val < y.val;
//         return x.type < y.type;
//     });

//     vector<pair<int, int>> value(temp.size());
//     vector<int> index(temp.size());

//     for (int i = 0; i < temp.size(); ++i){
//         value[i].first = temp[i].val;
//         value[i].second = temp[i].type;
//         index[i] = temp[i].idx;
//     }

//     int target, f;
//     int cow = 0;
//     for (int i = 1; i <= n; ++i){
//         // case 1
//         target = N[i].t - N[i].x - N[i].y;
//         f = lower_bound(value.begin(), value.end(), make_pair(target, 1LL)) - value.begin();
//         if (f < value.size() && value[f].first >= target){
//             if (check(G[index[f]], N[i], 1)){
//                 cow++;
//                 continue;
//             }
//         }

//         // case 2
//         target = N[i].t - N[i].x + N[i].y;
//         f = lower_bound(value.begin(), value.end(), make_pair(target, 2LL)) - value.begin();
//         if (f < value.size() && value[f].first >= target){
//             if (check(G[index[f]], N[i], 2)){
//                 cow++;
//                 continue;
//             }
//         }

//         // case 3
//         target = N[i].t + N[i].x + N[i].y;
//         f = lower_bound(value.begin(), value.end(), make_pair(target, 3LL)) - value.begin();
//         if (f < value.size() && value[f].first >= target){
//             if (check(G[index[f]], N[i], 3)){
//                 cow++;
//                 continue;
//             }
//         }

//         // case 4
//         target = N[i].t + N[i].x - N[i].y;
//         f = lower_bound(value.begin(), value.end(), make_pair(target, 4LL)) - value.begin();
//         if (f < value.size() && value[f].first >= target){
//             if (check(G[index[f]], N[i], 4)){
//                 cow++;
//                 continue;
//             }
//         }
//     }

//     cout << n - cow;

//     return 0;
// }

#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

struct Point {
    int x, y, t;

    Point (){};
};

bool can(const Point &gg, const Point &nn){
    int dx = gg.x - nn.x;
    int dy = gg.y - nn.y;
    int dt = gg.t - nn.t;

    return (dx * dx) + (dy * dy) <= (dt * dt);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    //     ray();
    // #endif

    int g, n; cin >> g >> n;
    vector<Point> G(g+1, Point()), N(n+1, Point());

    for (int i = 1; i <= g; ++i){
        cin >> G[i].x >> G[i].y >> G[i].t;
    }

    for (int i = 1; i <= n; ++i){
        cin >> N[i].x >> N[i].y >> N[i].t;
    }

    sort(G.begin()+1, G.end(), [](const auto &x, const auto &y){
        return x.t < y.t;
    });

    vector<int> time(G.size());
    for (int i = 1; i <= g; ++i){
        time[i] = G[i].t;
    }

    int cc = 0;
    for (int i = 1; i <= n; ++i){
        auto ff = lower_bound(time.begin()+1, time.end(), N[i].t);
        if (ff == time.end() && *ff == N[i].t) continue;

        int f = ff - time.begin();
        bool ch = 1;
        if (f <= g) if (!can(G[f], N[i])) ch = 0;
        if (f > 1) if (!can(N[i], G[f-1])) ch = 0;

        if (ch) cc++;
    }

    cout << n - cc;

    return 0;
}