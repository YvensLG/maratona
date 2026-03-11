#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = (M + 1) / 2;
const int maxn = 400005;

void solve(){
    int n, k; cin >> n >> k; 
    vector<int> resp(k); 
    for( int i = 0; i < n; i++ ){
        string s; cin >> s; 
        int id = 1; 
        while( id < s.size() && s[id] == s[id - 1] ) id++; 
        if( id == s.size() ) resp[s[0] - 'a'] = -1; 
        else if( resp[s[0] - 'a'] != -1 ) resp[s[0] - 'a'] += id; 
    }

    pair<int, char> opt( INF, '#' ); 
    for( int i = 0; i < k; i++ ) if( resp[i] != -1 ) opt = min( opt, make_pair( resp[i] + 1, (char)('a' + i) ) );

    if( opt.second == '#' ){ cout << "NO" << endl; return; }
    for( int i = 0; i < opt.first; i++ ) cout << opt.second; cout << endl; 
}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();

    return 0;
}