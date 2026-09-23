#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = (1 << 14) + 10;
    
int a[maxn], n;
vector<int> pf(maxn, 0);

int check(int l, int r, int turn){
    if (pf[r] - pf[l-1] == 0) return turn + (r - l);
    if ((pf[r] - pf[l-1]) % 2) return turn;

    int vmid = ((pf[r] - pf[l-1]) / 2) + pf[l-1];
    int mid = lower_bound(pf.begin(), pf.begin()+n+1, vmid) - pf.begin();
    if (pf[mid] != vmid || !(l <= mid && mid < r)) return turn;
    return max(check(l, mid, turn+1), check(mid+1, r, turn+1));
}

int solver(){
    cin >> n;
    pf[0] = 0;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pf[i] = pf[i-1] + a[i];
    }

    return check(1, n, 0);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ray("LIST");

    int t; cin >> t;

    while (t--) cout << solver() << '\n';

    return 0;
}