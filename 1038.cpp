#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;
int n, m; 

struct G {
    int st, en;

    G (){};
};

vector<G> a;

bool check(int x){
    int debt = 0, left = 0, nn = n;
    for (int i = 1; i <= m; ++i){
        int curr = (a[i].en - a[i].st + 1);
        if (i > 1 && debt > 0){
            debt -= (a[i].st - a[i-1].en - 1);
            debt -= left;
            left = 0;

            if (debt > 0){
                int temp = min(debt, curr);
                debt -= temp;
                curr -= temp;
            }
        }

        if (curr <= 0) continue;
        nn--;
        curr--;
        debt = x - 1;

        if (curr <= 0) continue;
        nn -= curr/x;
        left = curr % x;
    }

    if (nn <= 0) return 1;
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    cin >> n >> m;
    a.assign(m+1, G());

    int l, r = -1;
    for (int i = 1; i <= m; ++i){
        cin >> a[i].st >> a[i].en;
        r = max(r, a[i].en);
    }

    sort(a.begin()+1, a.end(), [](const auto &x, const auto &y){
        return x.st < y.st;
    });

    l = 1;
    while (l < r){
        int mid = (r + l + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << l << '\n';
    return 0;
}