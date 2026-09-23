#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1010;

struct Point {
    int x, y; 

    Point (){};
    Point (int x, int y): x(x), y(y) {};
};

Point H[maxn], G[maxn];
int dp[maxn][maxn][2];
int h, g;

int dist(const Point &aa, const Point &bb){
    return (aa.x - bb.x)*(aa.x - bb.x) + (aa.y - bb.y)*(aa.y - bb.y);
}

bool check(int i, int j){
    return (1 <= i and i <= h) and (0 <= j and j <= g);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);

    cin >> h >> g;
    for (int i = 1; i <= h; ++i){
        cin >> H[i].x >> H[i].y;
    }

    for (int i = 1; i <= g; ++i){
        cin >> G[i].x >> G[i].y;
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[1][0][1] = dp[1][0][0] = 0;
    for (int i = 1; i < h; ++i){
        for (int j = 0; j <= g; ++j){
            int d1, d2;

            if (!check(i-1, j)){
                d1 = INT_MAX;
            }
            else d1 = min(dp[i-1][j][0] + dist(H[i-1], H[i]), dp[i-1][j][1] + dist(G[j], H[i]));

            if (!check(i, j-1)){
                d2 = INT_MAX;
            }
            else {
                d2 = min(dp[i][j-1][0] + dist(H[i], G[j]), dp[i][j-1][1] + dist(G[j-1], G[j]));
            }

            dp[i][j][0] = min(dp[i][j][0], d1);
            dp[i][j][1] = min(dp[i][j][1], d2);
        }
    }

    cout << min(dp[h-1][g][0] + dist(H[h-1], H[h]), dp[h-1][g][1] + dist(G[g], H[h]));

    return 0;
}