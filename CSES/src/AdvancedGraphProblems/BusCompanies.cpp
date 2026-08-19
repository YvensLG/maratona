#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
 
int main(){
  int n, m; cin >> n >> m;
  vector<int> cost(m);
  vector<vector<int>> adj(n + m);
  for( int &x : cost ) cin >> x;
  for( int i = 0; i < m; i++ ){
    int k; cin >> k;
    while( k-- ){
      int id; cin >> id;
      id--;
      adj[id].push_back(n + i);
      adj[n + i].push_back(id);
    }
  }
 
  vector<ll> dist(n + m, inf);
 
  auto dijkstra = [&]( int source ){
    set<pair<ll, int>> s;
    s.insert({ 0, source });
    dist[source] = 0;
    while( !s.empty() ){
      int cur = s.begin()->second; s.erase(s.begin());
      for( int viz : adj[cur] ){
        ll d = ((cur >= n) ? cost[cur - n] : 0 );
        if( dist[viz] > dist[cur] + d ){
          s.erase({ dist[viz], viz });
          dist[viz] = dist[cur] + d;
          s.insert({ dist[viz], viz });
        }
      }
    }
  };
 
  dijkstra(0);
 
  for( int i = 0; i < n; i++ ) cout << dist[i] << " "; cout << endl;
}