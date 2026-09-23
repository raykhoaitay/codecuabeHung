#include <bits/stdc++.h>
using namespace std;
void openFile(string name) {string inp = name + ".inp";string out = name + ".out";freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}
void openFile(string inp = "i.inp", string out = "o.out") {freopen(inp.c_str(), "r", stdin);freopen(out.c_str(), "w", stdout);}

int main() {
    openFile(); 
    
    int n; cin >> n;
	vector<int> a(n);
	unordered_map<int, int> cow;
	int maxx = 0;
	for (int &x : a){
		cin >> x;
		cow[x]++;
		maxx = max(maxx, x);
	}

	int result = 1, check;
	for (int i = 2; i <= maxx; ++i){
		check = 0;
		for (int j = i; j <= maxx; j += i){
			check += cow[j];
			if (check >= 2){
				result = i;
				break;
			}
		}
	}

	cout << result;
    return 0;
}