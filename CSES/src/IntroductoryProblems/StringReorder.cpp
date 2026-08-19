#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;

bool check(vector<int> &v) {
    int sum = 0;
    for(int i = 0; i < 26; i++) {
        sum += v[i];
    }
    for(int i = 0; i < 26; i++) {
        if(v[i] > (sum + 1) / 2) {
            return false;
        }
    }
    return true;
}

int find_best(char pst, vector<int> &v) {
    int best = -1;
    for(int i = 0; i < 26; i++) {
        if(pst == 'A' + i || v[i] == 0) continue;
        v[i]--;
        if(check(v)) {
            best = i;
            break;
        }
        v[i]++;
    }
    return best;
}

void solve(){
    string s; cin >> s;
    vector<int> v(26);
    for(int i = 0; i < s.size(); i++){
        v[s[i] - 'A']++;
    }
    string ans = "";
    char pst = '$';

    while(ans.size() < s.size()) {
        int novo = find_best(pst, v);
        if(novo == -1) {
            cout << -1 << '\n';
            return;
        }
        ans += 'A' + novo;
        pst = 'A' + novo;
    }

    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}