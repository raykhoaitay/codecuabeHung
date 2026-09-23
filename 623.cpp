#include <bits/stdc++.h>

using namespace std;
void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2005;

int a[maxn], b[maxn], par[maxn*maxn], sz[maxn*maxn];

struct Edge {
    int x, y, w;

    Edge (int x, int y, int w): x(x), y(y), w(w) {};
};

int find(int v){
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);

    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);

    par[b] = a;
    sz[a] += sz[b];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    
    int A, B, n, m; cin >> A >> B >> n >> m;

    a[n+1] = A;
    a[0] = 0;

    b[m+1] = B;
    b[0] = 0;

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];

    sort(a+1, a+1+n);
    sort(b+1, b+1+m);

    vector<Edge> e;

    int nn = n+1;
    for (int i = 1; i <= m+1; ++i){
        for (int j = 1; j <= n; ++j){
            e.push_back({(i-1) * nn + j, (i-1)*nn + j+1, b[i] - b[i-1]});
        }
    }

    for (int j = 1; j <= n+1; ++j){
        for (int i = 1; i <= m; ++i){
            e.push_back({(i-1)*nn + j, i*nn + j, a[j] - a[j-1]});
        }
    }

    for (int i = 1; i < maxn * maxn; ++i){
        par[i] = i;
        sz[i] = 1;
    }    

    sort(e.begin(), e.end(), [](const Edge &aa, const Edge &bb){
        return aa.w < bb.w;
    });

    nn *= (m+1);
    nn--;
    long long cow = 0, cost = 0;
    for (const Edge &ed : e){
        if (cow == nn) break;

        if (find(ed.x) != find(ed.y)){
            cow++;
            cost += ed.w;

            join(ed.x, ed.y);
        }
    }

    cout << cost;
    return 0;   
}