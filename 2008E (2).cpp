#include <bits/stdc++.h>

using namespace std;

int solver(){
    int n;
    string s;
    cin >> n >> s;

    s = " " + s;

    if (n % 2 == 0){
        vector<int> odd(40, 0), even(40, 0);

        for (int i = 1; i <= n; ++i){
            if (i % 2 == 0){
                even[s[i] - 'a']++;
            } else odd[s[i] - 'a']++;
        }

        int m1 = *max_element(odd.begin(), odd.end()),
        m2 = *max_element(even.begin(), even.end());

        return (n/2 - m1) + (n/2 - m2);
    }
    else {
        vector<int> pfo(40, 0), pfe(40, 0), sfo(40, 0), sfe(40, 0);

        for (int i = 1; i <= n; ++i){
            if (i % 2 == 0){
                sfe[s[i] - 'a']++;
            } else sfo[s[i] - 'a']++;
        }

        int maxx = -1e9, m1, m2;
        for (int i = 1; i <= n; ++i){
            int c = 0;
            if (i % 2 == 0){
                sfe[s[i] - 'a']--;
                c = 1;
            }
            else sfo[s[i] - 'a']--;

            for (int j = 0; j < 40; ++j){
                m1 = max(pfe[j] + sfo[j], m1);
                m2 = max(pfo[j] + sfe[j], m2);
            }

            maxx = max(maxx, m1 + m2);
            m1 = 0, m2 = 0;
            if (c){
                pfe[s[i] - 'a']++;
            }
            else pfo[s[i] - 'a']++;
        }

        return (n - 1) - maxx + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--){
        cout << solver() << '\n';
    }

    return 0;
}