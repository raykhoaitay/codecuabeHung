#include <bits/stdc++.h>

using namespace std;

int W, H, U, D, L, R;
double pu, pd, pl, pr;
string g[10005];
bool vis[10005][25];
int d[10005][25];

int main() {
    freopen("PACHINKO.Inp", "r", stdin);
    freopen("PACHINKO.Out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> W >> H;
    cin >> U >> D >> L >> R;
    pu = U / 100.0; pd = D / 100.0; pl = L / 100.0; pr = R / 100.0;

    int st = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) cin >> g[i];
    for (int j = 0; j < W; ++j) {
        if (g[0][j] == '.') {
            vis[0][j] = 1;
            q.push({0, j});
            st++;
        }
    }

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
        double prob[] = {pu, pd, pl, pr};
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (prob[i] > 0 && nr >= 0 && nr < H && nc >= 0 && nc < W && g[nr][nc] == '.' && !vis[nr][nc]) {
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }

    int N = 0;
    memset(d, -1, sizeof(d));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (g[i][j] == '.' && vis[i][j]) d[i][j] = N++;

    if (N == 0) return 0;

    int bw = W, sz = 3 * bw + 1;
    vector<double> a(N * sz, 0.0), b(N, 0.0);

    for (int j = 0; j < W; ++j) if (d[0][j] != -1) b[d[0][j]] = 1.0 / st;

    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            if (d[r][c] == -1) continue;
            int u = d[r][c];
            double s = 0;
            if (r > 0 && g[r - 1][c] != 'X') s += pu;
            if (r < H - 1 && g[r + 1][c] != 'X') s += pd;
            if (c > 0 && g[r][c - 1] != 'X') s += pl;
            if (c < W - 1 && g[r][c + 1] != 'X') s += pr;

            a[u * sz + bw] = s;
            if (r > 0 && d[r - 1][c] != -1) a[u * sz + (d[r - 1][c] - u + bw)] = -pd;
            if (r < H - 1 && d[r + 1][c] != -1) a[u * sz + (d[r + 1][c] - u + bw)] = -pu;
            if (c > 0 && d[r][c - 1] != -1) a[u * sz + (d[r][c - 1] - u + bw)] = -pr;
            if (c < W - 1 && d[r][c + 1] != -1) a[u * sz + (d[r][c + 1] - u + bw)] = -pl;
        }
    }

    for (int i = 0; i < N; ++i) {
        int p = i;
        int lim = min(N - 1, i + bw);
        for (int k = i + 1; k <= lim; ++k)
            if (abs(a[k * sz + (i - k + bw)]) > abs(a[p * sz + (i - p + bw)])) p = k;

        if (p != i) {
            swap(b[i], b[p]);
            for (int j = i; j <= min(N - 1, i + 2 * bw); ++j)
                swap(a[i * sz + (j - i + bw)], a[p * sz + (j - p + bw)]);
        }

        double cur = a[i * sz + bw];
        if (abs(cur) < 1e-18) continue;
        for (int k = i + 1; k <= lim; ++k) {
            double f = a[k * sz + (i - k + bw)] / cur;
            b[k] -= f * b[i];
            for (int j = i; j <= min(N - 1, i + 2 * bw); ++j)
                a[k * sz + (j - k + bw)] -= f * a[i * sz + (j - i + bw)];
        }
    }

    vector<double> v(N, 0.0);
    for (int i = N - 1; i >= 0; --i) {
        double s = b[i];
        for (int j = i + 1; j <= min(N - 1, i + 2 * bw); ++j)
            s -= a[i * sz + (j - i + bw)] * v[j];
        v[i] = (abs(a[i * sz + bw]) > 1e-18) ? s / a[i * sz + bw] : 0;
    }

    cout << fixed << setprecision(8);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (g[i][j] == 'T') {
                double ans = 0;
                if (pd > 0 && i > 0 && d[i - 1][j] != -1) ans += v[d[i - 1][j]] * pd;
                if (pu > 0 && i < H - 1 && d[i + 1][j] != -1) ans += v[d[i + 1][j]] * pu;
                if (pr > 0 && j > 0 && d[i][j - 1] != -1) ans += v[d[i][j - 1]] * pr;
                if (pl > 0 && j < W - 1 && d[i][j + 1] != -1) ans += v[d[i][j + 1]] * pl;
                cout << ans << "\n";
            }
        }
    }

    return 0;
}