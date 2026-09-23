#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 2019;
const int maxn = 2e5+10;
int pf[maxn];
int powmod[maxn];

int dx, dy, d;
void ee(int a, int b){
    if (b == 0){
        dx = 1;
        dy = 0;
        d = a;
        return;
    }

    ee(b, a%b);
    int temp = dx;
    dx = dy;
    dy = temp - (a/b) * dy;
}

int modinv(int a){
    ee(a, mod);
    return (dx + mod) % mod;
}

int calc(int n){
    return n * (n-1)/2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    string s; cin >> s;
    int n = s.size();
    pf[0] = 0;
    powmod[0] = 1;

    vector<int> cow(2500, 0);
    cow[0]++;

    for (int i = 1; i <= n; ++i){
        pf[i] = ((pf[i-1] * 10) % mod + (s[i-1] - '0')) % mod;
        powmod[i] = (powmod[i-1] * 10) % mod;
        cow[((pf[i] * modinv(powmod[i])) % mod)]++;
    }

    int result = 0;
    for (int i = 0; i < 2500; ++i){
        result += calc(cow[i]);
    }

    cout << result;
    return 0;
}