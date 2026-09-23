#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int n; cin >> n;
    cin.ignore();
    string s;
    vector<pair<string, string>> rule(n);

    for (int i = 0; i < n; ++i){
        getline(cin, s);
        stringstream ss(s);
        int cow = 0;
        string a, b, temp;
        while (cow < 6){
            ss >> temp;
            // cout << temp << endl;
            if (cow == 0) a = temp;
            else if (cow == 5) b = temp;
            cow++;
        }
        rule[i].first = a, 
        rule[i].second = b;
    }

    vector<string> sample = {
        "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"
    };
    sort(sample.begin(), sample.end());

    do {
        int c3 = 1;
        for (int i = 0; i < n; ++i){
            int c1 = 0, c2 = 0;
            for (int j = 0; j < 7; ++j){
                if (sample[j] == rule[i].first && sample[j+1] == rule[i].second){
                    c1 = 1; break;
                }
                else if (sample[j+1] == rule[i].first && sample[j] == rule[i].second){
                    c2 = 2; break;
                }
            }

            if (c1 == 0 and c2 == 0){
                c3 = 0;
            }
        }

        if (!c3) continue;
        break;
    } while (next_permutation(sample.begin(), sample.end()));

    for (int i = 0; i < 8; ++i) cout << sample[i] << '\n';
    return 0;
}