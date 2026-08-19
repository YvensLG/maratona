#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
typedef vector<int> vi;

void pi(const string& s) {
    vi p(sz(s));
    for(int i = 1; i < sz(s); i++) {
        int g = p[i - 1];
        while(g && s[i] != s[g]) g = p[g - 1];
        p[i] = g + (s[i] == s[g]);
    }
    
    for(auto x : p) cout << x << ' ';
    cout << '\n';
}

void Z(const string& s) {
    vi z(sz(s));
    int l = -1, r = -1;
    for(int i = 1; i < sz(s); i++) {
        z[i] = i >= r ? 0 : min(r - i, z[i - l]);
        while(i + z[i] < sz(s) && s[i + z[i]] == s[z[i]]) z[i]++;
        if(i + z[i] > r) l = i, r = i + z[i];
    }
    for(auto x : z) cout << x << ' ';
    cout << '\n';
}

void solve() {
    string s; cin >> s;
    Z(s); pi(s);
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}