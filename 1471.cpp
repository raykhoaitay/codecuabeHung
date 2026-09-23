#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 5e5+10;
int a[maxn];

int solver(){
    int n, m; cin >> n >> m;
    vector<int> cycle;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        int x = a[i] % m;
        cycle.push_back(x);
        cycle.push_back(x+m);
    }

    sort(cycle.begin(), cycle.end());
    int minn = 1e18;
    if (n % 2 != 0){
        int length = n/2;
        int sl = 0, sr = 0;

        for (int i = 0; i < length; ++i){
            sl += cycle[length] - cycle[i]; 
        }

        for (int i = length + 1; i < n; ++i){
            sr += cycle[i] - cycle[length];
        }

        minn = sl + sr;
        for (int i = length + 1; i < 2*n-length; ++i){
            sl -= (cycle[i-1] - cycle[i-length-1]);
            sl += (cycle[i] - cycle[i-1]) * length;

            sr -= (cycle[i] - cycle[i-1]) * length;
            sr += (cycle[i + length] - cycle[i]);
            minn = min(minn, sl + sr);
        }
    }
    else {
        int ll = n/2, lr = n/2-1;
        int minnn;
        for (int _ = 0; _ < 2; ++_){
            int sl = 0, sr = 0;

            for (int i = 0; i < ll; ++i){
                sl += cycle[ll] - cycle[i];
            }

            for (int i = ll + 1; i < n; ++i){
                sr += cycle[i] - cycle[ll];
            }

            minnn = sl + sr;    

            for (int i = ll + 1; i < 2*n-lr; ++i){
                sl -= (cycle[i-1] - cycle[i - ll - 1]);
                sl += (cycle[i] - cycle[i-1]) * ll;

                sr -= (cycle[i] - cycle[i-1]) * lr;
                sr += (cycle[i + lr] - cycle[i]);

                minnn = min(minnn, sl + sr);
            }

            minn = min(minn, minnn);
            swap(ll, lr);
        }
    }

    return minn;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--) cout << solver() << '\n';

    return 0;
}