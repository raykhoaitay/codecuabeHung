#include <bits/stdc++.h>
#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout); }
void ray(string inp = "i.inp", string out = "o.out") {freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}

int mod = 1000000007;
int maxn = 1e6+5;

int nC2(int n){
    return n*(n-1)/2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        ray();
    #endif
   
    int n; cin >> n;
    vector<int> cow(maxn, 0);

    vector<int> mark(maxn, 1);
    for (int i = 2; i * i <= maxn; ++i){
        if (mark[i]){
            for (int j = i * i; j < maxn; j += i) mark[j] = 0;
        }
    }

    vector<int> mobius(maxn, 1);
    mobius[0] = 0;

    for (int i = 2; i < maxn; ++i){
        if (mark[i]){
            for (int j = i * i; j < maxn; j += i * i) mobius[j] = 0;
            for (int j = i; j < maxn; j += i) mobius[j] *= -1;
        }
    }

    int temp, maxx = -1e9;
    for (int i = 0; i < n; ++i){
        cin >> temp;
        if (maxx < temp) maxx = temp;
        cow[temp]++;
    }

    int pres = 0;
    for (int i = 2; i <= maxx; ++i){
        temp = 0;
        for (int j = i; j <= maxx; j += i) temp += cow[j];

        pres += nC2(temp) * mobius[i];
    }

    cout << nC2(n) + pres << '\n';

    return 0;
}