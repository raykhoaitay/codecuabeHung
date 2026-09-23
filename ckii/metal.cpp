#include <bits/stdc++.h>
using namespace std;

int n, a[205][205];
vector<int> v;
struct E { int u, v; };
vector<E> eg[40005];

int p[205], w[205];
vector<int> g[405];
int num[405], low[405], ti = 0, c[405], cnt = 0;
bool is[405];
stack<int> st;
vector<pair<int, vector<pair<int,int>>>> ss;

void in(int x) { 
    for(int i=0; i<=x; i++) { p[i] = i; w[i] = 0; } 
}

pair<int,int> f(int u) {
    if (u == p[u]) return {u, 0};
    auto r = f(p[u]);
    p[u] = r.first; w[u] ^= r.second;
    return {p[u], w[u]};
}

int j(int x, int y) {
    auto rx = f(x), ry = f(y);
    if (rx.first == ry.first) return rx.second == ry.second ? -1 : 0;
    p[rx.first] = ry.first;
    w[rx.first] = rx.second ^ ry.second ^ 1;
    return 1;
}

void tj(int u) {
    num[u] = low[u] = ++ti;
    st.push(u); is[u] = true;
    for(int x : g[u]) {
        if (!num[x]) { 
            tj(x); low[u] = min(low[u], low[x]); 
        }
        else if (is[x]) low[u] = min(low[u], num[x]);
    }
    if (low[u] == num[u]) {
        cnt++;
        while(true) {
            int x = st.top(); st.pop();
            is[x] = false; c[x] = cnt;
            if (u == x) break;
        }
    }
}

bool ck(int lim, const vector<pair<int,int>>& state) {
    int id[205]; memset(id, -1, sizeof(id));
    int k = 0;
    for(int i=0; i<n; i++) if (id[state[i].first] == -1) id[state[i].first] = k++;
    for(int i=0; i<2*k; i++) { g[i].clear(); num[i] = low[i] = c[i] = 0; }
    ti = cnt = 0;
    while(!st.empty()) st.pop();
    memset(is, 0, sizeof(is));

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if (a[i][j] > lim) {
                int ui = id[state[i].first], uj = id[state[j].first];
                int wi = state[i].second, wj = state[j].second;
                int x = (wi == 0) ? (2*ui) : (2*ui + 1);
                int y = (wj == 0) ? (2*uj) : (2*uj + 1);
                g[x].push_back(y ^ 1); g[y].push_back(x ^ 1);
            }
        }
    }
    for(int i=0; i<2*k; i++) if(!num[i]) tj(i);
    for(int i=0; i<k; i++) if(c[2*i] == c[2*i+1]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
        freopen("METAL.Inp", "r", stdin);
        freopen("METAL.Out", "w", stdout);

    cin >> n;
    v.push_back(0);
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-1-i; j++) {
            int x; cin >> x;
            a[i][i+j+1] = a[i+j+1][i] = x;
            v.push_back(x);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int m = v.size() - 1;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int pos = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
            eg[pos].push_back({i, j});
        }
    }
    in(n);
    for(int i=m; i>=0; i--) {
        vector<pair<int,int>> s(n);
        for(int u=0; u<n; u++) s[u] = f(u);
        bool ok = true, ch = false;
        for(auto e : eg[i]) {
            int res = j(e.u, e.v);
            if(res == -1) ok = false;
            if(res == 1) ch = true;
        }
        if(!ok) { ss.push_back({v[i], s}); break; }
        if(ch || i == 0) ss.push_back({v[i], s});
    }
    long long ans = 2e18;
    for(auto& p : ss) {
        int rb = p.first;
        int l = 0, r = m, best = v[m];
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(ck(v[mid], p.second)) {
                best = v[mid];
                r = mid - 1;
            } else l = mid + 1;
        }
        ans = min(ans, 1LL * best + rb);
    }
    cout << ans << "\n";
    return 0;
}