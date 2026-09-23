#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 0;

struct Box {
    int st, en;

    Box (){};
    bool operator<(const Box &other) const {
        return en > other.en;
    }
};

bool solver(){
    int n; cin >> n;
    vector<Box> a(n+1, Box());

    for (int i = 1; i <= n; ++i) cin >> a[i].st >> a[i].en;

    sort(a.begin()+1, a.end(), [](const Box &zit, const Box &zat){
        return zit.st < zat.st;
    });

    priority_queue<Box> pq;
    int time = 1, i = 1;

    while (i <= n){
        if (pq.empty()) time = max(time, a[i].st);
        while (i <= n && a[i].st <= time){
            pq.push(a[i]);
            i++;
        }

        if (!pq.empty()){
            if (pq.top().en >= time) pq.pop();
            else return false;
        }

        time++;
    }

    while (!pq.empty()){
        if (pq.top().en >= time) pq.pop();
        else return false;

        time++;
    }

    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    int t; cin >> t;
    while (t--){
        if (solver()) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}