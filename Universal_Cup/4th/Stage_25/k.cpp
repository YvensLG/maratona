#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n; cin >> n; 
    vector<int> ans; 

    set<pair<int, int>> s; 
    for( int i = 0; i < 2*n; i++ ){

        if( i%2 == 1 ){
            ans.push_back(s.rbegin()->second); 
            s.erase(prev(s.end())); 
        }
        
        int x; cin >> x; 
        s.insert({ x, i }); 
    }

    sort( ans.begin(), ans.end() ); 
    for( int x : ans ) cout << x + 1 << " "; cout << endl;
}   

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while( t-- )
    solve();

    return 0;
}
