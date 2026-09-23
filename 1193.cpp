#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1010;
char a[maxn][maxn];
int how[maxn][maxn];
int dx[4] = {1, 0, 0, -1}, dy[4] = {0, -1, 1, 0};
int n, m;

struct Point {
    int x, y;

    Point (){};
    Point (int x, int y): x(x), y(y) {};
};

bool check(int i, int j){
    return (1 <= i && i <= n) && (1 <= j && j <= m);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    cin >> n >> m;
    int sx, sy, ex, ey;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];

            if (a[i][j] == 'A'){
                sx = i, sy = j;
            }
            if (a[i][j] == 'B'){
                ex = i, ey = j;
            }
        }
    }

    memset(how, 0, sizeof(how));
    queue<Point> q;
    how[sx][sy] = -1;
    q.push({sx, sy});

    bool c = 0;
    while (!q.empty()){
        Point p = q.front();
        q.pop();

        if (p.x == ex && p.y == ey){
            c = 1;
            break;
        }

        for (int i = 0; i < 4; ++i){
            int nx = p.x + dx[i],
            ny = p.y + dy[i];

            if (!check(nx, ny)){
                continue;
            }
            if (how[nx][ny] != 0 || a[nx][ny] == '#') continue;
            how[nx][ny] = i + 1; 
            q.push({nx, ny});
        }
    }

    if (!c){
        cout << "NO\n";
        return 0;
    }

    vector<int> d;
    int cx = ex, cy = ey;

    while (how[cx][cy] != -1){
        d.push_back(how[cx][cy]);

        int idx = how[cx][cy] - 1;
        cx -= dx[idx];
        cy -= dy[idx];
    }

    cout << "YES\n";
    reverse(d.begin(), d.end());
    cout << d.size() << '\n';

    for (const int &x : d){
        if (x == 1) cout << 'D';
        else if (x == 2) cout << 'L';
        else if (x == 3) cout << 'R';
        else cout << 'U';
    }
    
    return 0;
}