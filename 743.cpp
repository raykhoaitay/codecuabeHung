#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10; 

int cow[maxn], flag[maxn], a[maxn], stage[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
    int n; cin >> n;
    memset(cow, 0, sizeof(cow));
    memset(flag, 0, sizeof(flag));
    memset(stage, 0, sizeof(stage));

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        cow[a[i]]++;
        flag[a[i]]++;
    }

    stack<int> ball; 
    stage[1] = 0;
    for (int i = 1; i <= n; ++i){
        if (a[i] == 0) continue;
        if (!ball.empty()){
            int x = ball.top();
            if (flag[a[i]] == cow[a[i]]){
                stage[i] = stage[x] + 1;
            }
        }

        flag[a[i]]--;
        if (flag[a[i]] == 0 && cow[a[i]] > 1){
            if (!ball.empty()) {
                if (a[ball.top()] != a[i]){
                    cout << -1;
                    return 0;
                }
                else ball.pop();
            }
            continue;
        }

        if (flag[a[i]] == cow[a[i]] - 1 && flag[a[i]] != 0) ball.push(i);
    }

    cout << *max_element(stage, stage+n+1) + 1;
    return 0;
}