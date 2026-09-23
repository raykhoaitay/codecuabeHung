#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e4+10;

struct Cow {
    int st, en; 

    Cow (){};
    bool operator <(const Cow &other) const {
        return en > other.en;
    }
};

int chick[maxn];
vector<Cow> cow(maxn);  

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("helpcross.in", "r", stdin);
    // freopen("helpcross.out", "w", stdout);
    ray();

    int c, n; cin >> c >> n;
    for (int i = 1; i <= c; ++i) cin >> chick[i];
    for (int i = 1; i <= n; ++i){
        cin >> cow[i].st >> cow[i].en;
    }

    sort(chick+1, chick+c+1, [](const auto &x, const auto &y){
        return x < y;
    });

    sort(cow.begin()+1, cow.begin()+n+1, [](const auto &x, const auto &y){
        return x.st < y.st;
    });

    int i = 1, j = 1, cnt = 0;
    priority_queue<Cow> pq;
    while (i <= c){
        while (j <= n && cow[j].st <= chick[i]){
            pq.push(cow[j]);
            j++;
        }

        while (!pq.empty()){
            int x = pq.top().en;
            pq.pop();

            if (x >= chick[i]){
                cnt++;
                break;
            }
        }
        i++;
    }

    cout << cnt << '\n';

    return 0;
}