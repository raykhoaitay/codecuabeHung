#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2050;

int n, x, y;
char stt[maxn][maxn];
int a[maxn][maxn];

bool check(int i, int j){
    return (1 <= i && i <= n) && (j <= n && 1 <= j);
}

int solver(){
    cin >> n >> y >> x;
    memset(a, 0, sizeof(a));

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> stt[i][j];

            if (stt[i][j] == 'B'){
                a[i][j] = 2;

                if (check(i-x, j-y)) a[i-x][j-y] = 2;
            }
        }
    }   

    int c = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (stt[i][j] == 'W'){
                if (a[i][j] == 2){
                    c = 1;
                    continue;
                }
                a[i][j] = 1;

                if (check(i-x, j-y)){
                    if (a[i-x][j-y] == 0) a[i-x][j-y] = 1;
                }
            }
            else if (stt[i][j] == 'G'){
                if (!check(i-x, j-y)){
                    a[i][j] = 2;
                    continue;
                }

                int &x1 = a[i][j], &x2 = a[i-x][j-y];
                if (x2 == 2) continue;
                if (x1 == 2) continue;
                x2 = 1, x1 = 2;
            }   
        }
    }

    if (c){
        return -1;
    }

    int cow = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j) if (a[i][j] == 2) cow++;
    }

    return cow;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--){
        cout << solver() << '\n';
    }

    return 0;
}