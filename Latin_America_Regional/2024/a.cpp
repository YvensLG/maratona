#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep( i, a, b ) for( int i = a; i < (b); i++ )

using ll = long long; 
using pii = pair<int, int>; 
using vi = vector<int>; 

void solve(){
    string s; cin >> s;
    int n = sz(s);
    sort(all(s));
    s.erase(unique(s.begin(), s.end()), s.end());
    cout << n - sz(s) << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();
}