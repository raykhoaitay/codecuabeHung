#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1010;

int dp[maxn][maxn];

struct Point {
    int x, y;

    Point (){};
    Point (int x, int y): x(x), y(y) {};
};

vector<Point> FJ(maxn), B(maxn);
int n, m, xa, ya, xb, yb; 

bool check(int i, int j){
    return (0 <= i and i <= n) and (0 <= j and j <= m);
}

int dist(const Point &aa, const Point &bb){
    return (aa.x - bb.x)*(aa.x - bb.x) + (aa.y - bb.y)*(aa.y - bb.y);
}

Point renew(const Point &other, char c){
    if (c == 'N') return {other.x, other.y+1};
    if (c == 'S') return {other.x, other.y-1};
    if (c == 'E') return {other.x+1, other.y};
    if (c == 'W') return {other.x-1, other.y};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);

    cin >> n >> m >> xa >> ya >> xb >> yb;
    string s, t; cin >> s >> t;

    memset(dp, 0, sizeof(dp));
    FJ[0] = {xa, ya};
    B[0] = {xb, yb};

    char c;
    for (int i = 1; i <= n; ++i){
        c = s[i-1];
        FJ[i] = renew(FJ[i-1], c);
    }

    for (int i = 1; i <= m; ++i){
        B[i] = renew(B[i-1], (char)t[i-1]);
    }

    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= m; ++j){
            if (i == 0 && j == 0) continue;
            int d1, d2, d3;

            if (!check(i, j-1)) d1 = INT_MAX;
            else d1 = dp[i][j-1];

            if (!check(i-1, j-1)) d2 = INT_MAX;
            else d2 = dp[i-1][j-1];

            if (!check(i-1, j)) d3 = INT_MAX;
            else d3 = dp[i-1][j];

            dp[i][j] = min(d1, min(d2, d3)) + dist(FJ[i], B[j]);
        }
    }

    cout << dp[n][m];
    return 0;
}