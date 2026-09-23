#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1010;

int a[maxn][maxn], n, m;
int vis[maxn][maxn];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct Point {
    int x, y;

    Point (){};
    Point (int x, int y): x(x), y(y) {};
};

bool check(int i, int j){   
    return (1 <= i && i <= n) && (1 <= j && j <= m);
}
queue<Point> q; 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    cin >> n >> m;
    int xa, ya, xb, yb; 

    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            char c; cin >> c;

            if (c == '#') a[i][j] = -1;
            else if (c == 'A'){
                xa = i;
                ya = j;
            }
            else if (c == 'B'){
                xb = i; yb = j;
            }
        }
    }
    
    vis[xa][ya] = -1;
    q.push({xa, ya});

    while (!q.empty()){
        Point f = q.front();
        q.pop();

        if (f.x == xb && f.y == yb) break;

        for (int i = 0; i < 4; ++i){
            int nx = f.x + dx[i];
            int ny = f.y + dy[i];

            if (!check(nx, ny) || vis[nx][ny] != 0 || a[nx][ny] == -1) continue;
            vis[nx][ny] = i+1;
            q.push({nx, ny});
        }
    }

    if (vis[xb][yb] == 0){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    int nx = xb, ny = yb;

    vector<char> result;
    char vl;
    while (vis[nx][ny] != -1){
        int t = vis[nx][ny];
        
        if (t == 1) vl = 'D';
        else if (t == 2) vl = 'R';
        else if (t == 3) vl = 'U';
        else if (t == 4) vl = 'L';
        result.push_back(vl);
        nx = nx - dx[t-1];
        ny = ny - dy[t-1];
    }

    cout << result.size() << '\n';
    reverse(result.begin(), result.end());
    for (const char &x : result) cout << x;

    return 0;
}