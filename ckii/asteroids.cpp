#include <bits/stdc++.h>

using namespace std;

typedef double D;
const D E = 1e-9;

struct P {
    D x, y;
};

P operator+(P a, P b) { return {a.x + b.x, a.y + b.y}; }
P operator-(P a, P b) { return {a.x - b.x, a.y - b.y}; }
P operator*(P a, D k) { return {a.x * k, a.y * k}; }

D cr(P a, P b) { return a.x * b.y - a.y * b.x; }
D dt(P a, P b) { return a.x * b.x + a.y * b.y; }
D no(P a) { return sqrt(dt(a, a)); }

D ar(vector<P>& p) {
    D s = 0;
    int n = p.size();
    for (int i = 0; i < n; ++i) s += cr(p[i], p[(i + 1) % n]);
    return s / 2.0;
}

void nl(vector<P>& p) {
    if (ar(p) < 0) reverse(p.begin(), p.end());
}

D ds(P p, P a, P b) {
    D l = dt(a - b, a - b);
    if (l < E) return no(p - a);
    D t = max(0.0, min(1.0, dt(p - a, b - a) / l));
    return no(p - (a + (b - a) * t));
}

bool in(P p, const vector<P>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i)
        if (cr(a[(i + 1) % n] - a[i], p - a[i]) < -E) return 0;
    return 1;
}

int sgn(D x) { return (x > E) - (x < -E); }

bool si(P a, P b, P c, P d) {
    D c1 = cr(b - a, c - a), c2 = cr(b - a, d - a);
    D c3 = cr(d - c, a - c), c4 = cr(d - c, b - c);
    return (sgn(c1) * sgn(c2) < 0 && sgn(c3) * sgn(c4) < 0);
}

D pd(const vector<P>& A, const vector<P>& B) {
    if (in(A[0], B) || in(B[0], A)) return 0;
    int n = A.size(), m = B.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (si(A[i], A[(i + 1) % n], B[j], B[(j + 1) % m])) return 0;
    D r = 1e9;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            r = min(r, ds(A[i], B[j], B[(j + 1) % m]));
            r = min(r, ds(B[j], A[i], A[(i + 1) % n]));
        }
    return r;
}

vector<P> cl(vector<P> a, P p1, P p2) {
    vector<P> r;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        P c = a[i], d = a[(i + 1) % n];
        D cc = cr(p2 - p1, c - p1), dc = cr(p2 - p1, d - p1);
        if (cc >= -E) r.push_back(c);
        if (sgn(cc) * sgn(dc) < 0) {
            D t = -cc / cr(p2 - p1, d - c);
            r.push_back(c + (d - c) * t);
        }
    }
    return r;
}

D ia(vector<P> a, vector<P> b) {
    int m = b.size();
    for (int i = 0; i < m; ++i) {
        if (a.empty()) break;
        a = cl(a, b[i], b[(i + 1) % m]);
    }
    return abs(ar(a));
}

vector<P> A0, B0;
P vA, vB;

vector<P> po(const vector<P>& a, P v, D t) {
    vector<P> r = a;
    for (auto& p : r) {
        p.x += v.x * t;
        p.y += v.y * t;
    }
    return r;
}

D dt_t(D t) { return pd(po(A0, vA, t), po(B0, vB, t)); }
D ar_t(D t) { return ia(po(A0, vA, t), po(B0, vB, t)); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("ASTEROIDS.INP", "r", stdin);
    freopen("ASTEROIDS.OUT", "w", stdout);

    int n;
    if (!(cin >> n)) return 0;
    vector<P> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i].x >> A[i].y;
    cin >> vA.x >> vA.y;

    int m;
    cin >> m;
    vector<P> B(m);
    for (int i = 0; i < m; ++i) cin >> B[i].x >> B[i].y;
    cin >> vB.x >> vB.y;

    nl(A);
    nl(B);
    A0 = A;
    B0 = B;

    D l = 0, r = 200000;
    for (int i = 0; i < 100; ++i) {
        D m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (dt_t(m1) < dt_t(m2)) r = m2;
        else l = m1;
    }

    D tm = l;
    if (dt_t(tm) > 1e-7) {
        cout << "never" << endl;
        return 0;
    }

    D l1 = 0, r1 = tm;
    for (int i = 0; i < 80; ++i) {
        D md = (l1 + r1) / 2;
        if (dt_t(md) <= 1e-7) r1 = md;
        else l1 = md;
    }
    D t1 = l1;

    D l2 = tm, r2 = 200000;
    for (int i = 0; i < 80; ++i) {
        D md = (l2 + r2) / 2;
        if (dt_t(md) <= 1e-7) l2 = md;
        else r2 = md;
    }
    D t2 = l2;

    l = t1;
    r = t2;
    for (int i = 0; i < 100; ++i) {
        D m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (ar_t(m1) > ar_t(m2)) r = m2;
        else l = m1;
    }

    if (ar_t(l) < 1e-8) cout << fixed << setprecision(6) << t1 << endl;
    else cout << fixed << setprecision(6) << l << endl;

    return 0;
}