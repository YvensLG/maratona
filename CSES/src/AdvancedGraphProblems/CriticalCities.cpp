#include <bits/stdc++.h>
using namespace std; 
 
#define bug(x) cout << #x << " " << x << endl;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define FOR(i, a, b) for(int i = a; i < b; i++)
 
using vi = vector<int>; 
using pii = pair<int, int>;
 
const int maxn = 1e5; 
 
vi adj[2][maxn];
 
vi bfs( int n ){
    vi lvl(n, n); 
    lvl[0] = 0; 
    queue<int> q; 
    for( q.push(0); !q.empty(); q.pop() ){
        int u = q.front();
        for( int v : adj[0][u] ) if( lvl[v] > lvl[u] + 1 )
            lvl[v] = lvl[u] + 1, q.push(v); 
    }    
 
 
    set<pii> s; 
 
    vi marc(n), ans; 
 
    marc[n - 1] = true; 
    for( s.insert({ lvl[n - 1], n - 1}); !s.empty(); ){
        int u = s.rbegin()->second; s.erase(prev(s.end()));
        if( s.empty() ) ans.push_back(u); 
 
        for( int v : adj[1][u] ) if( !marc[v] )
            marc[v] = true, s.insert({ lvl[v], v }); 
    }
    sort(all(ans)); 
 
    return ans; 
}
 
void solve(){
    int n, m; cin >> n >> m; 
    while( m-- ){
        int u, v; cin >> u >> v; u--; v--; 
        if( u == n - 1 || v == 0 ) continue;
        adj[0][u].push_back(v); 
        adj[1][v].push_back(u); 
    }
 
    vi ans = bfs(n); 
 
    cout << sz(ans) << '\n'; 
    for( int x : ans ) cout << x + 1 << " "; cout << '\n'; 
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    solve(); 
}
