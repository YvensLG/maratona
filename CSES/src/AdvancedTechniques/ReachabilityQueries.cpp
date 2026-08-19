#include <bits/stdc++.h>
using namespace std;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define FOR(i, a, b) for( int i = a; i < b; i++ )
 
using vi = vector<int>; 
using ll = long long;
 
const int maxn = 5e4; 
 
struct Kosaraju{
    vector<vector<vi>> adj; 
    vector<vi> adjc; 
    vector<bitset<maxn>> b; 
    vi scc; 
 
    Kosaraju( vector<vector<vi>> adj ) : adj(adj) {
        int n = sz(adj[0]); 
        scc = vi(n, -1); 
        adjc.resize(n); 
        b.resize(n);
 
        kosaraju();
    }
 
    void dfs( int u, int t, vi &o ){
        for( int v : adj[t][u] ) if( scc[v] == -1 ){
            scc[v] = scc[u]; dfs( v, t, o ); 
        }
        if(!t) o.push_back(u); 
    }
 
    void kosaraju(){
        int n = sz(adj[0]); 
 
        vi o; 
        FOR(i, 0, n) if( scc[i] == -1 ){
            scc[i] = i; dfs( i, 0, o ); 
        }
 
        fill(all(scc), -1); 
        reverse(all(o)); 
 
        for( int i : o ){
            if( scc[i] == -1 ){
                scc[i] = i; dfs( i, 1, o ); 
            }
            b[scc[i]][i] = 1; 
        } 
 
        reverse(all(o)); 
 
        for( int i : o ){
            for( int v : adj[0][i] ) if( scc[i] != scc[v] )
                adjc[scc[i]].push_back(scc[v]); 
 
            sort(all(adjc[i])); 
            adjc[i].erase(unique(all(adjc[i])), adjc[i].end());
 
            for( int v : adjc[i] ) b[i] |= b[v]; 
        }
    }
};
 
void solve(){
    int n, m, q; cin >> n >> m >> q; 
    vector<vector<vi>> adj(2, vector<vi>(n)); 
    while( m-- ){
        int u, v; cin >> u >> v; u--; v--; 
        adj[0][u].push_back(v); 
        adj[1][v].push_back(u); 
    }
 
    Kosaraju kos(adj); 
 
    while( q-- ){
        int u, v; cin >> u >> v; u--; v--; 
        int scc = kos.scc[u]; 
        cout << ((kos.b[scc][v]) ? "YES" : "NO" ) << '\n'; 
    }
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve(); 
}