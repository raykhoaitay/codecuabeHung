#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

struct E {
    int val, idx;

    E(){};
};

int val[maxn], idx[maxn], diff[maxn];

void solver(){
    int n; cin >> n;
    vector<E> a(n+1, E());

    for (int i = 1; i <= n; ++i){
        cin >> a[i].val;
        a[i].idx = i;
    }

    sort(a.begin()+1, a.end(), [](const auto &x, const auto &y){
        return x.val < y.val;
    });

    for (int i = 1; i <= n; ++i){
        val[i] = a[i].val;
        idx[i] = a[i].idx;
    }

    memset(diff, 0, sizeof(diff));
    int i = 1, j = 1;
    int curr = 0, add = 0;
    while (j <= n){
        curr += val[j];
        while (curr >= val[j+1] && j+1 <= n){
            j++;
            curr += val[j];
        }

        add += (j - i + 1);
        diff[i] += (add - 1);
        diff[j+1] -= (add - 1);

        j++; i = j;
    }

    vector<int> pre(n+1, 0);
    vector<E> re(n+1, E());
    
    for (int i = 1; i <= n; ++i){
        pre[i] = pre[i-1] + diff[i];

        re[i].val = pre[i];
        re[i].idx = idx[i];
    }

    sort(re.begin()+1, re.end(), [](const auto &x, const auto &y){
        return x.idx < y.idx;
    });

    for (int i = 1; i <= n; ++i){
        cout << re[i].val << ' ';
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--) solver();

    return 0;
}