#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e5+10;

struct Cow {
    int st, en, idx;

    Cow (){};

    bool operator <(const Cow &other) const {
        return idx > other.idx;
    }
};

vector<Cow> a(maxn, Cow());

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    int n; cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].st >> a[i].en;
        a[i].idx = i;
    }

    sort(a.begin()+1, a.begin()+1+n, [](const auto &x, const auto &y){
        return x.st < y.st;
    });

    priority_queue<Cow> pq;

    int i = 1, maxx = 0, curr = 0;
    while (true){
        while (i <= n && a[i].st <= curr){
            pq.push(a[i]);
            ++i;
        }
        if (i == n+1) break;

        while (a[i].st > curr){
            if (!pq.empty()){
                maxx = max(maxx, curr - pq.top().st);
                curr += pq.top().en;
                pq.pop();
            }
            else curr = a[i].st;
        }
    }

    while (!pq.empty()){
        maxx = max(maxx, curr - pq.top().st);
        curr += pq.top().en;
        pq.pop();
    }

    cout << maxx;
    return 0;
}