#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

struct Element {
    int v, i;

    Element() {};
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
        cin >> a[i].v;
        a[i].i = i;
    }

    sort(a.begin()+1, a.end(), [](const Element &a, const Element &b){
        return a.v < b.v;
    });

    for (int i = 1; i <= n-2; ++i){
        int j = i+1, k = n, target = x - a[i].v;
        while (j < k){
            if (a[j].v + a[k].v == target){
                cout << a[i].i << ' ' << a[j].i << ' ' << a[k].i << '\n';
                return 0;
            }
            else if (a[j].v + a[k].v < target) j++;
            else k--;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}