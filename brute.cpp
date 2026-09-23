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

    

    string s; cin >> s;
    int q, n = s.size();
    for (int i = 1; i <= n; ++i) a[i] = s[i-1] - '0';

    cin >> q;
    while (q--){
        int t; cin >> t;
        if (t == 1){
            int k; cin >> k;
            a[k] ^= 1;
        }
        else {
            int l, r; cin >> l >> r;
            stack<int> st;
            for (int i = l; i <= r; ++i){
                if (st.empty()){
                    st.push(a[i]);
                    continue;
                }

                int x = st.top();
                if (x == 0){
                    if (a[i] == 1){
                        st.pop();
                        continue;
                    }
                }

                st.push(a[i]);
            }

            cout << st.size() << '\n';
        }
    }

    return 0;
}