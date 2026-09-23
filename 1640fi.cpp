#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

struct Element {
    int val, idx;

    Element (){};
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n, x; cin >> n >> x;
    vector<Element> a(n+1, Element());

    for (int i = 1; i <= n; ++i){
        cin >> a[i].val;
        a[i].idx = i;
    }

    sort(a.begin()+1, a.end(), [](const Element &a, const Element &b){
        return a.val < b.val;
    });

    int i = 1, j = n;
    while (i < j){
        if (a[i].val + a[j].val == x){
            int q = a[i].idx, w = a[j].idx;
            if (q > w) swap(q, w);

            cout << q << ' ' << w;
            return 0;
        }
        else if (a[i].val + a[j].val > x) j--;
        else i++;
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}