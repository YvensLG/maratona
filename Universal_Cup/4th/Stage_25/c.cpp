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

    int cur_id = 0; 

    vector<vector<int>> adj; 

    map<pii, int> id; 
    auto get_id = [&]( int a, int b ){
        if( id.count(pii(a, b)) == 0 ){
            id[pii(a, b)] = cur_id++; 
            adj.emplace_back();
            adj.emplace_back();
            adj.emplace_back();
        }
        return id[pii(a, b)]; 
    };

    auto join = [&]( int a, int b, int c ){
        int u = get_id(a, b); 
        int v = get_id(b, c);

        adj[3*u].push_back(3*v + 1); 
        
        adj[3*u + 1].push_back(3*v + 2); 

        adj[3*u + 2].push_back(3*v); 
    };

    for( int i = 0; i < n; i++ ){
        int a, b, c; cin >> a >> b >> c; 
        join( a, b, c ); 
        join( a, c, b ); 
        join( b, a, c ); 
        join( b, c, a ); 
        join( c, a, b ); 
        join( c, b, a ); 
    }

    vector<int> marc(3*adj.size(), -1); 

    function<void(int)> dfs = [&]( int u ){ 
        for( int v : adj[u] ) if( marc[v] == -1 ){
            marc[v] = marc[u];
            dfs( v );
        }
    };

    for( int i = 0; i < 3*cur_id; i++ ) if( marc[i] == -1 ){
        marc[i] = i; 
        dfs( i ); 
    } 

    for( int i = 0; i < cur_id; i++ ){
        if( marc[3*i] == marc[3*i + 1] || marc[3*i + 1] == marc[3*i + 2] || marc[3*i + 2] == marc[3*i] ){
            cout << "yes" << endl; return; 
        }
    }
    cout << "no" << endl;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while( t-- )
    solve();

    return 0;
}
