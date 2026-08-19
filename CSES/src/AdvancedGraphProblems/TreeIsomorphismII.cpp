#include <bits/stdc++.h>
using namespace std;
 
using pii = pair<int, int>;
 
map<vector<int>, int> mp;
vector<vector<vector<int>>> adj;
vector<vector<int>> sub;
int cont = 0;
 
int converte( vector<int> &v ){
  if( mp[v] == 0 ) mp[v] = ++cont;
  return mp[v];
}
 
int dfs( int cur, int pai, int t ){
  vector<int> v;
  for( int viz : adj[t][cur] ) if( viz != pai ) v.push_back(dfs( viz, cur, t ));
  sort( v.begin(), v.end() );
  return converte(v);
}
 
void dfs_init( int cur, int pai, int t ){
  sub[t][cur] = 1;
  for( int viz : adj[t][cur] ) if( viz != pai ){ dfs_init( viz, cur, t ); sub[t][cur] += sub[t][viz]; }
}
 
int find_centroid( int cur, int pai, int t ){
  for( int viz : adj[t][cur] ) if( viz != pai && sub[t][viz] > sub[t][0]/2 ) return find_centroid( viz, cur, t );
  return cur;
}
 
pii get_centroids( int t ){
  dfs_init( 0, 0, t );
  int centroid = find_centroid( 0, 0, t );
  pii big( 0, 0 );
  for( int viz : adj[t][centroid] ) if( sub[t][viz] <= sub[t][centroid] ) big = max( big, pii( sub[t][viz], viz ) );
  return pii( centroid, big.second );
}
 
void solve(){
  mp.clear(); adj.clear(); sub.clear();
  cont = 0;
  int n; cin >> n;
  adj.resize(2, vector<vector<int>>(n));
  sub.resize(2, vector<int>(n));
 
  for( int i = 0; i < n - 1; i++ ){
    int a, b; cin >> a >> b;
    a--; b--;
    adj[0][a].push_back(b);
    adj[0][b].push_back(a);
  }
 
  auto [a1, a2] = get_centroids(0);
 
  for( int i = 0; i < n - 1; i++ ){
    int a, b; cin >> a >> b;
    a--; b--;
    adj[1][a].push_back(b);
    adj[1][b].push_back(a);
  }
 
  auto [b1, b2] = get_centroids(1);
 
  cout << (( dfs( a1, a1, 0 ) == dfs( b1, b1, 1 ) || dfs( a2, a2, 0 ) == dfs( b1, b1, 1 ) ) ? "YES" : "NO" ) << endl;
}
 
int main(){
  int t; cin >> t;
  while( t-- ) solve();
}