#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;
int flag[150], a[150], mark[150];

struct Cow {
    int id, t; 
    Cow(){};
    Cow(int id, int t): id(id), t(t){};
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ray();
    int n, m, k; cin >> n >> m >> k;
    vector<int> order(m);

    memset(flag, 0, sizeof(flag));
    memset(mark, 0, sizeof(mark));
    for (int i = 0; i < m; ++i){
        cin >> order[i];
        flag[order[i]]++;
    }

    vector<Cow> fixed(k);
    queue<int> moc;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < k; ++i){
        cin >> fixed[i].id >> fixed[i].t;
        a[fixed[i].t] = fixed[i].id;

        flag[fixed[i].id]++;
        if (fixed[i].id == 1){
            cout << fixed[i].t << '\n';
            return 0;
        }

        if (flag[fixed[i].id] == 2){ 
            moc.push(fixed[i].id);
            mark[fixed[i].id]++;
        }
    }

    sort(fixed.begin(), fixed.end(), [](const Cow &a, const Cow &b){
        return a.t < b.t;
    });

    if (flag[1] == 0){
        while (!moc.empty()){
            int x = moc.front();
            moc.pop();
            int idx = find(order.begin(), order.end(), x) - order.begin() - 1;
            

            for (int i = 0; i < k; ++i){
                if (fixed[i].id == x){
                    for (int j = fixed[i].t; j > 0; j--){
                        if (a[j] == 0){
                            if (mark[order[idx]] > 0 || (idx < 0)) break;
                            a[j] = order[idx];
                            mark[order[idx]]++;
                            idx--;
                        }
                    }
                }
            }
        }
        for (int i = 1; i < 150; ++i){
            if (a[i] == 0){
                cout << i << endl;
                return 0;
            }
        }    
    }
    else {
        int idx = 0;
        for (int i = 1; i < 150; ++i){
            if (flag[order[idx]] == 1 && a[i] == 0){
                a[i] = order[idx];
                idx++;
            }
            else if (flag[order[idx]] == 2){
                if (a[i] == order[idx]){
                    idx++;
                }
            }

            if (idx >= m){
                break;
            }
        }

        for (int i = 1; i < 150; ++i){
            if (a[i] == 1){
                cout << i << '\n';
                return 0;
            }
        }
    }

    return 0;
}