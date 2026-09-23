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

vector<int> base = {4, 8, 15, 16, 23, 42};
vector<int> check;

void solver(int &a, int &b, int &c, int h){
    check.assign(2000, 0);
    cout << "? " << h+1 << " " << h+2 << endl;
    int rp1, rp2;
    cin >> rp1;
    cout << "? " << h+1 << " " << h+3 << endl;
    cin >> rp2;

    for (int i = 0; i < 6; ++i){
        for (int j = i+1; j < 6; ++j){
            if (base[i] * base[j] == rp1 || base[i] * base[j] == rp2){
                check[base[i]]++;
                check[base[j]]++;
                if (check[base[i]] == 2){
                    a = base[i];
                    break;
                }
                if (check[base[j]] == 2){
                    a = base[j];
                    break;
                }
            }
        }
    }

    b = rp1/a;
    c = rp2/a;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int a, b, c, d, e, f;
    solver(a, b, c, 0);
    solver(d, e, f, 3);

    cout << "! " << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << endl;

    return 0;
}