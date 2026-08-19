#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
vector<int> dist;
 
void bfs( int source ){
  fill( dist.begin(), dist.end(), 1e9 );
  queue<int> fila;
  fila.push(2*source);
  dist[2*source] = 0;
  while( !fila.empty() ){
    int cur = fila.front(); fila.pop();
    for( int viz : adj[cur/2] ){
      int id = (dist[cur] + 1)%2;
      if( dist[2*viz + id] > dist[cur] + 1 ){ fila.push(2*viz + id); dist[2*viz + id] = dist[cur] + 1; }
    }
  }
}
 
int main(){
  ios::sync_with_stdio(false); cin.tie(NULL);
  int n, m, q; cin >> n >> m >> q;
  adj.resize(n);
  dist.resize(2*n);
  while( m-- ){
    int a, b; cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
 
  vector<vector<tuple<int, int, int>>> queries(n);
  vector<bool> resp(q);
  for( int i = 0; i < q; i++ ){
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    queries[a].emplace_back( b, c, i );
  }
 
  for( int i = 0; i < n; i++ ){
    bfs(i);
    for( auto [b, x, id] : queries[i] ){
      int parity = x%2;
      resp[id] = (( dist[2*b + parity] <= x ) ? true : false );
    }
  }
 
  for( bool x : resp ) cout << (( x ) ? "YES" : "NO" ) << endl;
}