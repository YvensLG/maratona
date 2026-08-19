#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
 
int main(){
  ios::sync_with_stdio(false); cin.tie(NULL);
  int n, m; cin >> n >> m;
 
  vector<vector<pair<int, int>>> adj[2];
  adj[0].resize(n);
  adj[1].resize(n);
 
  while( m-- ){
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    adj[0][a].push_back({ b, c });
    adj[1][b].push_back({ a, c });
  }
 
  vector<ll> dist;
 
  auto dijkstra = [&]( int source ){
    dist.resize(n, inf);
    set<pair<ll, int>> s;
 
    s.insert({ 0, source });
    dist[source] = 0;
 
    while( !s.empty() ){
      int u = s.begin()->second;
      s.erase(s.begin());
 
      for( auto [v, d] : adj[1][u] )
        if( dist[v] > dist[u] + d ){
          s.erase({ dist[v], v });
          dist[v] = dist[u] + d;
          s.insert({ dist[v], v });
        }
    }
  };
 
  dijkstra( n - 1 );
 
  auto solve = [&](){
    vector<int> ans;
 
    set<pair<ll, int>> s;
 
    s.insert({ 0, 0 });
 
    while( !s.empty() ){
      auto [dist_u, u] = *s.begin();
      s.erase(s.begin());
 
      if( s.empty() ) ans.push_back(u);
 
      for( auto [v, d] : adj[0][u] )
        if( dist_u + d + dist[v] == dist[0] )
          s.insert({ dist_u + d, v });
    }
 
    sort( ans.begin(), ans.end() );
    return ans;
  };
 
  vector<int> ans = solve();
 
  cout << ans.size() << endl;
  for( int x : ans ) cout << x + 1 << " ";
  cout << endl;
}