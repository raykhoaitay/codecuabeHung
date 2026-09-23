#include <bits/stdc++.h>
#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout); }
void ray(string inp = "i.inp", string out = "o.out") {freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}

int mod = 1000000007;

int powmod(int a, int b, int mod = mod){
    int result = 1;
    while (b > 0){
        if (b & 1) result = (result * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }

    return result;
}

int dx, dy;
void eE(int a, int b){
    if (b == 0){
        dx = 1;
        dy = 0;
        return;
    }

    eE(b, a % b);
    int temp = dx;
    dx = dy;
    dy = temp - (a / b) * dy;
}

int modinv(int a){
    eE(a, mod);
    return (dx + mod) % mod;
}

int tcsn(int a, int q){
    int top = (powmod(a, q) - 1);
    int bottom = modinv(a - 1);

    return (top * bottom) % mod;
}

int tcsc(int n, int mod){
    return (n*(n+1)/2) % mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        ray();
    #endif
   
    int n; cin >> n;
    int x, k, num = 1, sum = 1, p = 1, d = 1;

    while (n--){
        cin >> x >> k;

        num = (num * (k + 1)) % mod;
        sum = (sum * tcsn(x, k + 1)) % mod;
        p = (powmod(p, k+1) * powmod(x, (tcsc(k, mod-1) * d) % (mod-1))) % mod;
        d = (d * (k+1)) % (mod-1);
    }

    cout << num << ' ' << sum << ' ' << p << '\n';
    return 0;
}