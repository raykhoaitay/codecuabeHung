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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    int cow = 0;
    string rp;

    for (int i = 0; i < prime.size(); ++i){
        cout << prime[i] << endl;
        cin >> rp;

        if (rp == "yes"){
            cow++;
            if (cow > 1){
                cout << "composite" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < 4; ++i){
        cout << prime[i] * prime[i] << endl;
        cin >> rp;

        if (rp == "yes"){
            cout << "composite" << endl;
            return 0;
        }
    }

    cout << "prime" << endl;
    return 0;
}