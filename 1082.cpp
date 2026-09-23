#include <bits/stdc++.h>
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout); }
void ray(string inp = "i.inp", string out = "o.out") {freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}

int mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ray();
   
    long long n; cin >> n;
    long long x = 1, y = 0, co, result = 0;

    while (y < n){
        co = n/x;
        y = n/co;
        
        long long fs = (x + y) % mod,
        number = (y - x + 1) % mod;
        long long sum = (((fs * number) % mod) * 500000004) % mod;
        result = (result + (sum * co) % mod) % mod;

        x = y + 1;
    }

    cout << result;
    return 0;
}