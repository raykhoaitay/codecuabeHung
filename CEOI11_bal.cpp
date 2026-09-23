#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

int x[maxn];
double r[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x[i] >> r[i];
    }

    stack<int> ball;
    for (int i = 1; i <= n; ++i){
        while (!ball.empty()){
            int j = ball.top();

            double tg = (x[i] - x[j]) * (x[i] - x[j]) / (4 * r[j]);

            if (r[i] > tg){
                r[i] = tg;
            }
            if (r[i] > r[j]){
                ball.pop();
            }
            else break;
        }

        ball.push(i);
    }

    for (int i = 1; i <= n; ++i){
        cout << fixed << setprecision(3) << r[i] << '\n';
    }

    return 0;
}