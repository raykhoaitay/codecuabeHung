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
const int maxn = 0;

int getLISLength(const vector<int>& A) {
    vector<int> tail;
    
    for (int i : A){
        auto it = lower_bound(tail.begin(), tail.end(), i);

        if (it == tail.end()) tail.push_back(x);
        else *it = x;
    }
    
    return tail.size();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    

    return 0;
}