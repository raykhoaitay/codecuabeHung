#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {
    string inp = name + ".inp";
    string out = name + ".out";
    freopen(inp.c_str(), "r", stdin);
    freopen(out.c_str(), "w", stdout);
}

void ray() {
    freopen("i.inp", "r", stdin);
    freopen("o.out", "w", stdout);
}

int mod = 1000000007;
int maxn = 0;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    vector<int> a, pr;
    int rp;
    while (t--){
        int n; cin >> n;
        a.assign(n, 0);
        pr.assign(n+1, 0);

        for (int i = 0; i < n; ++i){
            cin >> a[i];
            pr[i+1] = pr[i] + a[i];
        }

        int l = 0, r = n-1;
        while (l < r){
            int mid = (r + l) /2;

            cout << "? " << mid - l + 1 << ' ';
            for (int i = l; i <= mid; ++i){
                cout << i+1 << ' ';
            }
            cout << endl;

            cin >> rp;
            if (rp != pr[mid+1] - pr[l]){
                r = mid;
            }
            else l = mid+1;
        }

        cout << "! " << l+1 << endl;
    }

    return 0;
}