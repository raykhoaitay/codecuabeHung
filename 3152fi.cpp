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

    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    priority_queue<int, vector<int>, greater<int>> pq(a+1, a+1+min(n, k));
    
    for (int i = k+1; i <= n; ++i){
        pq.push(a[i]);

        cout << pq.top() << ' ';
        pq.pop();
    }

    while (!pq.empty()){
        cout << pq.top() << ' ';
        pq.pop();
    }
    return 0;
}