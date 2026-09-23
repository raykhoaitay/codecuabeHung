#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

int a[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int x, n; cin >> x >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    priority_queue<int, vector<int>, greater<int>> pq(a+1, a+n+1);
    int cost = 0;

    while (pq.size() > 1){
        int x1 = pq.top();
        pq.pop();
        int x2 = pq.top();
        pq.pop();

        cost += x1 + x2;
        pq.push(x1+x2);
    }

    cout << cost << '\n';
    return 0;
}