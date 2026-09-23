#include <bits/stdc++.h>

using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

int sf[maxn], pf[maxn * 4];

void update(int v, int l, int r, int pos, int val){
    if (l == r){
        pf[v] = max(pf[v], val);
    }
    else {
        int m = (l + r) / 2;
        if (pos <= m){
            update(2*v, l, m, pos, val);
        }
        else update (2*v+1, m+1, r, pos, val);

        pf[v] = max(pf[2*v], pf[2*v+1]);
    }
}

int query(int v, int tl, int tr, int l, int r){
    if (l > r) return -1;
    if (l == tl && r == tr){
        return pf[v];
    }
    else {
        int tm = (tl + tr) / 2;
        int q1 = query(2*v, tl, tm, l, min(r, tm));
        int q2 = query(2*v+1, tm+1, tr, max(l, tm+1), r);

        return max(q1, q2);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    vector<int> a(n);
    memset(sf, 0, sizeof(sf));
    memset(pf, 0, sizeof(pf));

    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    
    vector<int> tail;   
    int maxx2 = 0, maxx3 = 0, maxx4 = 0, maxx5 = 0;
    for (int i = n-1; i+1; --i){
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if (i != n-1) maxx5 = max(maxx5, a[i]);
        auto it = lower_bound(tail.begin(), tail.end(), a[i]*-1);
        if (it == tail.end()){
            tail.push_back(a[i]*-1);
            sf[i] = tail.size();
        }
        else {
            *it = a[i]*-1;
            sf[i] = it - tail.begin() + 1;
        }
        maxx4 = max(sf[i], maxx4);
    }

    update(1, 0, n-1, a[0], 1);
    int maxx = 0;
    for (int i = 1; i < n-1; ++i){
        int cow = query(1, 0, n-1, 0, a[i+1]-2);
        maxx = max(maxx, cow + 1 + sf[i+1]);

        int c = query(1, 0, n-1, 0, a[i]-1);
        update(1, 0, n-1, a[i], c+1);
    }

    maxx3 = query(1, 0, n-1, 0, maxx5)+1;
    for (int i = 1; i < n; ++i){
        int temp = sf[i];
        if (a[i] != 1){
            temp++;
        }

        maxx2 = max(maxx2, temp);
    }

    cout << max(max(maxx, maxx2), max(maxx3, maxx4));
    return 0;
}