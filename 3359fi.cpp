// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣶⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠟⠁⠁⠹⣿⡿⠀⠀⠀⠀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠃⠀⠀⠀⠀⠀⠀⠀⣠⠴⣿⡿⠉⣿⣭⣭⡍⠙⢹⣯⣭⣽⡟⠉⠉⣩⢿⣿⡟⠉
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⠁⠀⠀⠀⠀⠀⠀⢀⡴⠃⣼⣿⠃⠀⢀⣿⣿⣷⡀⠀⣸⡟⠀⠀⢀⠞⠁⣾⡿⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⠃⢀⣤⣄⠀⠀⠀⢀⡾⠶⢶⣿⠇⠀⠀⣾⠃⠘⣿⣷⣠⡿⠁⠀⣠⠿⠶⣾⣿⠃⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⠏⠀⣿⠈⠛⠀⢀⡴⠋⠀⢀⣿⡟⠀⠀⣸⡟⠀⠀⠘⣿⣿⠃⣀⡼⠁⠀⣰⣿⠏⠀⠀⠀
// ⠀⠀⢀⣀⣀⣀⣀⣾⣿⠏⠀⠀⠈⠓⠒⠚⠋⠀⣀⣚⣛⣛⣛⣋⡛⠛⠛⠃⠀⠀⠘⠛⠛⡁⠀⡀⣛⣛⠛⠛⢢⣤⡀
// ⢰⡞⠉⠉⢉⣿⣿⣿⣿⣦⣤⣀⠀⠀⠀⣠⠞⠋⠉⠉⣻⣿⠏⠉⠙⢳⣦⠀⢠⣀⣀⣀⣀⣀⣢⡞⢻⣿⡇⠀⠻⢿⣿
// ⠘⢧⣠⣤⣾⣿⠟⠋⠙⠻⣿⣿⣦⣄⣰⡏⠀⠀⣴⢀⣿⣿⠀⠁⠀⢸⣿⡆⠘⢻⣿⡟⠛⠛⣿⠃⢸⣿⡇⠀⠀⢸⣿
// ⠀⠀⠀⠀⢀⣀⣀⣀⣀⠀⠀⠈⠙⠛⠿⢿⣷⠿⠃⣼⣿⠃⠀⠀⣀⣾⣿⠃⢀⣿⣿⢀⣠⡞⠁⠀⢸⣿⠇⠀⠀⣾⠃
// ⠀⠀⢠⣟⡉⢠⡟⠀⠉⣷⢲⡶⢲⠖⢲⡞⠃⠀⢠⣿⡟⠹⣷⣾⠛⠉⠀⠀⣼⣿⠋⠉⣿⠁⠀⠀⣼⣿⠀⢀⡼⠁⠀
// ⠀⠀⠈⠉⢻⣿⠁⢀⣴⠟⣿⠓⣟⢠⡿⠁⡀⠀⣾⣿⠀⠀⢻⣿⣆⠀⠀⣰⣿⣟⠀⣀⣰⡾⠃⠀⣿⡟⣠⠞⠀⠀⠀
// ⠀⠀⠀⢠⣿⣿⣯⣭⣤⣿⣿⣿⣿⣿⣿⡟⠁⣸⣿⠇⠀⠀⠀⠻⣿⣆⠛⠛⠛⠛⠛⠛⠛⠁⠀⢰⣿⡿⠃⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠴⠾⠿⠿⡤⠆⠀⠀⠀⠙⢿⣷⡀⠀⠀⢰⣷⣄⢀⣠⠟⠋⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣦⣀⠀⠉⠉⠉⠱⢶⣶⠀⠀⠀⠀⠀⠀⠀⠀⠀
#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 3010;

char a[maxn][maxn];
bool dp[maxn][maxn];

int n; 
bool check(int i, int j){
    return 1 <= i and 1 <= j and i <= n and j <= n;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    cin >> n;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }

    memset(dp, false, sizeof(dp));
    dp[1][1] = 1;

    string result = "";
    result += a[1][1];
    for (int k = 2; k <= 2*n-1; ++k){
        int minn = 150;
        int j;
        for (int i = 1; i <= k; ++i){
            j = k - i + 1;
            if (!check(i, j)) continue;

            bool d1, d2;
            if (!check(i-1, j)) d1 = false;
            else d1 = dp[i-1][j];

            if (!check(i, j-1)) d2 = false;
            else d2 = dp[i][j-1];
            
            if (d1 | d2){
                minn = min(minn, (int) a[i][j]);
                dp[i][j] = 1;
            } 
        }

        for (int i = 1; i <= k; ++i){
            j = k - i + 1;
            if (!check(i, j)) continue;
            if ((int)a[i][j] != minn) dp[i][j] = 0;
        }

        result += (char) minn;
    }

    cout << result << '\n';
    return 0;
}

