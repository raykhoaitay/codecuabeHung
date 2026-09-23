#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

struct Edge {
    int u, v, w;

    Edge (){
        w = 0;
    };

    Edge (int u, int v): u(u), v(v) {
        w = 0;
    };
};

vector<Edge> a;
int par[maxn], sz[maxn];

int find(int v){
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}

void joint(int a, int b){
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

    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector<Edge> ncheck;
    for (int i = 1; i <= n; ++i){
        int temp; cin >> temp;
        par[i] = i;
        sz[i] = 1;
        if (temp != i){
            ncheck.emplace_back(temp, i);
        }
    }

    if (ncheck.size() == 0){
        cout << -1 << '\n';
        return 0;
    }

    a.assign(m+1, Edge());
    for (int i = 1; i <= m; ++i){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }

    sort(a.begin()+1, a.end(), [](const auto &x, const auto &y){
        return x.w > y.w;
    });

    int i = 0, j = 1, nn = ncheck.size();
    int minn = 1e9;
    while (i < nn){
        while (find(ncheck[i].u) != find(ncheck[i].v)){
            joint(a[j].u, a[j].v);
            minn = min(minn, a[j].w);
            j++;
        }

        i++;
    }

    cout << minn << '\n';
    return 0;
}