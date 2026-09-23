#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
struct pt {
    ld x, y;
    int id;
};
struct it {
    ld u, w;
    vector<short> p;
};
ld eps = 1e-7;
void fn(vector<it>& v, it nw) {
    vector<it> nv;
    bool ok = true;
    for (auto& e : v) {
        bool en = (e.u <= nw.u + eps) && (e.w >= nw.w - eps);
        bool ne = (nw.u <= e.u + eps) && (nw.w >= e.w - eps);
        if (en && e.p <= nw.p) {
            ok = false;
            nv.push_back(e);
        } else if (ne && nw.p <= e.p) {
        } else {
            nv.push_back(e);
        }
    }
    if (ok) nv.push_back(nw);
    v = nv;
}
int main() {
    freopen("SKIING.INP", "r", stdin);
    freopen("SKIING.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ld vy, am;
    if (!(cin >> n >> vy >> am)) return 0;
    if (vy <= eps) {
        cout << "Cannot visit any targets\n";
        return 0;
    }
    vector<pt> ar;
    ar.push_back({0.0, 0.0, 0});
    for (int i = 1; i <= n; i++) {
        ld x, y; cin >> x >> y;
        if (y > eps) ar.push_back({x, y, i});
    }
    sort(ar.begin() + 1, ar.end(), [](const pt& a, const pt& b) {
        return a.y < b.y;
    });
    int m = ar.size() - 1;
    vector<vector<vector<it>>> dp(m + 1, vector<vector<it>>(m + 1));
    dp[0][0].push_back({0.0, 0.0, {}});
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < i; j++) {
            if (ar[j].y >= ar[i].y - eps) continue;
            ld t = (ar[i].y - ar[j].y) / vy;
            ld dx = ar[i].x - ar[j].x;
            for (int l = 0; l <= j; l++) {
                if (dp[j][l].empty()) continue;
                for (auto& cr : dp[j][l]) {
                    ld mn = dx / t - am * t / 2.0;
                    ld mx = dx / t + am * t / 2.0;
                    ld u = max(cr.u, mn);
                    ld w = min(cr.w, mx);
                    if (u > w + eps) continue;
                    ld vl = w * t + am * t * t / 2.0 - dx;
                    if (vl < 0) vl = 0;
                    ld xu = w + am * t - 2.0 * sqrt(am * vl);
                    ld vr = dx - u * t + am * t * t / 2.0;
                    if (vr < 0) vr = 0;
                    ld xw = u - am * t + 2.0 * sqrt(am * vr);
                    if (xu > xw + eps) continue;
                    vector<short> np = cr.p;
                    np.push_back(ar[i].id);
                    fn(dp[i][l + 1], {xu, xw, np});
                }
            }
        }
    }
    int ml = -1;
    vector<short> rs;
    for (int l = m; l >= 1; l--) {
        for (int i = 1; i <= m; i++) {
            for (auto& cr : dp[i][l]) {
                if (ml == -1 || cr.p < rs) {
                    ml = l;
                    rs = cr.p;
                }
            }
        }
        if (ml != -1) break;
    }
    if (ml == -1) {
        cout << "Cannot visit any targets\n";
    } else {
        for (int i = 0; i < rs.size(); i++) {
            cout << rs[i] << (i + 1 == rs.size() ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}