#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e4+10;
int a[maxn];
int n, tmax; 

bool check(int k){
    priority_queue<int, vector<int>, greater<int>> pq(a+1, a+1+k);

    int maxx = -1e9;
    for (int i = k + 1; i <= n; ++i){
        int x = pq.top();
        pq.pop();

        maxx = max(x + a[i], maxx);
        pq.push(x + a[i]);
    }

    return maxx <= tmax;
}   

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    cin >> n >> tmax;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int l = 1, r = n;
    while (l < r){
        int mid = (l + r) / 2;

        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';
    return 0;
}