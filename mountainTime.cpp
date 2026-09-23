#include <bits/stdc++.h>

#define int long long
using namespace std;

void ray(string name) {string inp = name + ".inp"; string out = name + ".out"; freopen(inp.c_str(), "r", stdin); freopen(out.c_str(), "w", stdout);}
void ray() {freopen("i.inp", "r", stdin); freopen("o.out", "w", stdout);}

int mod = 1000000007;
const int maxn = 1e3+5;
int aa[maxn][maxn], par[maxn*maxn], flag[maxn][maxn], result[maxn][maxn];
vector<vector<int>> dadv(maxn*maxn, vector<int> ());
int n, m;
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};

struct Node {
    int val, idx;

    Node (){};
    Node (int val, int idx): val(val), idx(idx){};
};
vector<Node> node;

pair<int, int> decode(int cood){
    int x = cood/m;
    int y = cood%m;

    if (y == 0){
        x--;
        y = m;
    }
    return {x+1, y};
}

int encode(int x, int y){
    return (x-1)*m + y;
}

bool check(int x, int y){
    return (1 <= x && x <= n) && (1 <= y && y <= m);
}

int find(int v){
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}

void joint(int a, int b, int c){
    a = find(a);
    b = find(b);
    if (a == b) return;

    pair<int, int> cda = decode(a),
    cdb = decode(b);
    if (aa[cda.first][cda.second] > aa[cdb.first][cdb.second]) swap(a, b);
    cda = decode(a), cdb = decode(b);

    if (aa[cda.first][cda.second] < aa[cdb.first][cdb.second]){
        for (const int &x : dadv[a]){
            pair<int, int> from = decode(x);
            result[from.first][from.second] = aa[from.first][from.second] - node[c].val;
        }
    }
    else if (aa[cda.first][cda.second] == aa[cdb.first][cdb.second]){
        for (const int &x : dadv[a]) dadv[b].push_back(x);
    }
    
    par[a] = b;
    dadv[a].clear();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        ray();
    #endif

    cin >> n >> m;

    int minn = 1e9, maxx = -1e9;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> aa[i][j];
            int temp = encode(i, j);
            node.emplace_back(aa[i][j], temp);
            minn = min(minn, aa[i][j]);
            maxx = max(maxx, aa[i][j]);

            par[temp] = temp;
            dadv[temp].push_back(temp);
        }
    }

    sort(node.begin(), node.end(), [](const Node &x, const Node &y){
        return x.val > y.val;
    });

    memset(flag, -1, sizeof(flag));
    memset(result, -1, sizeof(result));
    for (int i = 0; i < node.size(); ++i){
        pair<int, int> cd = decode(node[i].idx);
        flag[cd.first][cd.second] = 1;
        for (int j = 0; j < 4; ++j){
            int nx = cd.first + dx[j],
            ny = cd.second + dy[j];

            if (check(nx, ny) == false) continue;
            if (flag[nx][ny] == 1){
                joint(node[i].idx, encode(nx, ny), i);
            }
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (result[i][j] == -1) cout << aa[i][j] - minn << ' ';
            else cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    
    return 0;
}