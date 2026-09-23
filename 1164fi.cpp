#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 2e5+10;

struct Customer {
    int st, en, idx, odx;

    Customer (){};

    bool operator<(const Customer &other) const {
        return en > other.en;
    }
};

vector<Customer> a(maxn, Customer());
int numero[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int n; cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].st >> a[i].en;
        a[i].odx = i;
    }

    sort(a.begin()+1, a.begin()+1+n, [](const auto &x, const auto &y){
        if (x.st != y.st) return x.st < y.st;
        return x.en < y.en;
    });

    for (int i = 1; i <= n; ++i) a[i].idx = i;

    priority_queue<Customer> pq;
    stack<int> available;
    memset(numero, 0, sizeof(numero));

    for (int i = 1; i <= n; ++i){
        while (!pq.empty()){
            Customer x = pq.top();

            if (x.en < a[i].st){
                available.push(numero[x.odx]);
                pq.pop();
            }
            else break;
        }

        pq.push(a[i]);
        if (available.empty()) numero[a[i].odx] = pq.size();
        else {
            numero[a[i].odx] = available.top();
            available.pop();
        }
    }

    cout << *max_element(numero+1, numero+n+1) << '\n';
    for (int i = 1; i <= n; ++i) cout << numero[i] << ' ';

    return 0;
}