#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

int a[maxn];
struct Query {
    int a, b, idx, ans;

    Query() {};
} qr[maxn];

int start[maxn];
struct Fenwick {
    int t[maxn], n;

    void init(int n){
        this->n = n;
        memset(t, 0, sizeof(t));
    }

    void update(int idx, int val){
        for (; idx <= n; idx += (idx & -idx)) t[idx] += val;
    }

    int query(int idx){
        int ans = 0;
        for (; idx; idx -= (idx & -idx)) ans += t[idx];

        return ans;
    }
} fen;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, q; cin >> n >> q;
    vector<int> b = {0};

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        b.push_back(a[i]);
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for (int i = 1; i <= n; ++i){
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    for (int i = 1; i <= q; ++i){
        cin >> qr[i].a >> qr[i].b;
        qr[i].idx = i;
    }

    sort(qr+1, qr+q+1, [](const Query &a, const Query &b){
        if (a.b == b.b) return a.a < b.a;
        return a.b < b.b;
    });

    memset(start, 0, sizeof(start));
    fen.init(n+1);
    int idxa = 1;
    for (int i = 1; i <= q; ++i){
        while (idxa <= qr[i].b){
            fen.update(idxa, 1);

            if (start[a[idxa]]){
                fen.update(start[a[idxa]], -1);
            }

            start[a[idxa]] = idxa;
            idxa++;
        }

        qr[i].ans = fen.query(qr[i].b) - fen.query(qr[i].a - 1);
    }

    sort(qr+1, qr+q+1, [](const Query &a, const Query &b){
        return a.idx < b.idx;
    });

    for (int i = 1; i <= q; ++i){
        cout << qr[i].ans << '\n';
    }

    return 0;
}