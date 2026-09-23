#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

struct Element {
    int n, v;

    Element(){};
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    //     ray();
    // #endif

    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    int n; cin >> n;
    vector<Element> a(n, Element());

    for (int i = 0; i < n; ++i){
        cin >> a[i].n >> a[i].v;
    }

    sort(a.begin(), a.end(), [](const Element &a, const Element &b){
        return a.v < b.v;
    });

    int i = 0, j = n-1;
    int maxx = -1e9;

    while (i <= j){
        maxx = max(maxx, a[i].v + a[j].v);
        
        if (i == j){
            break;
        }
        if (a[i].n == a[j].n){
            a[i].n = a[j].n = 0;
            i++;
            j--;
        }
        else if (a[i].n < a[j].n){
            a[j].n -= a[i].n;
            a[i].n = 0;
            i++;
        }
        else {
            a[i].n -= a[j].n;
            a[j].n = 0;
            j--;
        }
    }

    cout << maxx << '\n';
    return 0;
}