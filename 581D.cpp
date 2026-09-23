#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

struct Logo {
    int x, y, id;

    Logo (){};
};

bool cp(int n){
    int x = sqrt(n);
    return x * x == n;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    vector<Logo> lg(3, Logo());
    int need = 0;
    for (int i = 0; i < 3; ++i){
        cin >> lg[i].x >> lg[i].y;
        need += (lg[i].x * lg[i].y);
        lg[i].id = i;
    }

    if (!cp(need)){
        cout << -1 << '\n';
        return 0;
    }

    for (int mask = 0; mask < (1 << 3); ++mask){
        vector<Logo> a = lg;

        for (int i = 0; i < 3; ++i){
            if (mask & (1 << i)){
                swap(a[i].x, a[i].y);
            }
        }

        if ((a[0].x == a[1].x && a[0].x == a[2].x) && ((int) sqrt(need) == (a[0].y + a[1].y + a[2].y))){
            cout << (int) sqrt(need) << '\n';
            for (int _ = 0; _ < 3; ++_){
                char target = 'A' + a[_].id; 
                for (int i = 0; i < a[_].y; ++i){
                    for (int j = 0; j < a[_].x; ++j){
                        cout << target;
                    }
                    cout << '\n';
                }
            }
            return 0;
        }
    }

    do {
        for (int mask = 0; mask < (1 << 3); ++mask){
            vector<Logo> a = lg;
            for (int i = 0; i < 3; ++i){
                if (mask & (1 << i)){
                    swap(a[i].x, a[i].y);
                }
            }

            if ((a[0].y + a[1].y == a[2].y) && (a[0].x == a[1].x)){
                int curr = (a[0].x + a[2].x) * a[2].y;
                if (curr - need > 0) continue;

                cout << (int) sqrt(need) << '\n';
                for (int i = 0; i < 2; ++i){
                    char target = 'A' + a[i].id;
                    for (int j = 0; j < a[i].y; ++j){
                        for (int k = 0; k < a[i].x; ++k){
                            cout << target;
                        }
                        for (int k = 0; k < a[2].x; ++k){
                            cout << (char)('A' + a[2].id);
                        }
                        cout << '\n';
                    }
                }
                return 0;
            }
        }
    } while (next_permutation(lg.begin(), lg.end(), [](const Logo &a, const Logo &b){
        return a.id < b.id;
    }));

    cout << -1;
    return 0;
}