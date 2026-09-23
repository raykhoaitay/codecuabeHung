#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;
int n, m = 2, a[maxn], dvs[maxn];

int query(int x, int op){
    int cow = 0;
    for (int i = 1; i * i <= x; ++i){
        if (x % i == 0 && i <= m){
            dvs[i] += op;
            if (op == 1 && dvs[i] == 1) cow++;
            else if (op == -1 && dvs[i] == 0) cow++;

            if (i != x/i && x/i <= m){
                dvs[x/i] += op;
                if (op == 1 && dvs[x/i] == 1) cow++;
                else if (op == -1 && dvs[x/i] == 0) cow++;
            }
        }
    }

    return cow;
}

int solver(){
    cin >> n >> m;
    int ex[maxn];
    memset(ex, 0, sizeof(ex));
    memset(dvs, 0, sizeof(dvs));

    vector<int> wt;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        ex[a[i]]++;

        if (ex[a[i]] == 1) wt.push_back(a[i]);
    }

    sort(wt.begin(), wt.end());
    int sz = wt.size(), i = 0, j = 0;
    int curr = 0, minn = 1e9;
    while (j < sz){
        curr += query(wt[j], 1);

        while (curr == m){
            minn = min(minn, wt[j] - wt[i]);
            curr -= query(wt[i], -1);
            i++;
        }

        j++;
    }

    return (minn == 1e9) ? -1 : minn;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--){
        cout << solver() << '\n';
    }


    return 0;
}