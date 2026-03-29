#include <bits/stdc++.h>
#define int long long
using namespace std;

using ll = long long;
const ll INF = 0x3f3f3f3f;

const int np = 2;
vector<int> prime = {1000000000+7, 1000000000+9};
vector<int> pref[np];
vector<int> suf[np];

string s, c;

void calc() {
    for(int i = 0; i < np; i++) {
        pref[i].resize(s.size());
        pref[i][0] = s[0] - '0';
    }
    for(int i = 1; i < s.size(); i++) {
        for(int p = 0; p < np; p++) {
            pref[p][i] = (pref[p][i - 1] * 10 + s[i] - '0') % prime[p];
        }
    }

    for(int i = 0; i < np; i++) {
        suf[i].resize(s.size());
        suf[i][(int)s.size() - 1] = 0;
    }
    for(int p = 0; p < np; p++) {
        int pot = 1;
        for(int i = (int)s.size() - 2; i >= 0; i--) {
            suf[p][i] = (suf[p][i + 1] + pot * (s[i + 1] - '0')) % prime[p];
            pot = (pot * 10) % prime[p];
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> c;

    calc();
    
    vector<bool> ans(s.size(), 1);
    for(int p = 0; p < np; p++) {
        int sc = c[0] - '0';
        for(int i = 1; i < c.size(); i++) {
            sc = (sc * 10 + c[i] - '0') % prime[p];
        }
        for(int i = 0; i < (int)s.size() - 1; i++) {
            if(s[i + 1] == '0') ans[i] = 0;
            else if(pref[p][i] != (sc * suf[p][i]) % prime[p]) ans[i] = 0;
        }
    }

    for(int i = 0; i < ans.size(); i++){
        if(ans[i]) {
            for(int j = 0; j <= i; j++) cout << s[j];
            cout << ' ';
            for(int j = i + 1; j < s.size(); j++) cout << s[j];
            cout << '\n';
            return 0;
        }
    }
    

}