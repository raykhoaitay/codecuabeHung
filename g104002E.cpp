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

    int n; cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n/2; ++i){
        pq.push(a[2*i]);
        pq.push(a[2*i-1]);

        pq.pop();
    }

    int sum = 0;
    while (!pq.empty()){
        sum += pq.top();
        pq.pop();
    }

    cout << sum << '\n';

    return 0;
}