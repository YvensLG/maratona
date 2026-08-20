#include <bits/stdc++.h>
using namespace std;
 
const int inf = 2e9;
 
int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  int tot_rows = 0, tot_cols = 0;
  int source = 2*n, sink = 2*n + 1;
 
  int N = 2*n + 2;
  vector<vector<int>> capacity( N, vector<int>(N)), adj(N), cost(N, vector<int>(N));
  for( int i = 0; i < n; i++ ){
    int x; cin >> x;
    tot_rows += x;
 
    adj[i].push_back(source);
    adj[source].push_back(i);
 
    capacity[source][i] = x;
  }
 
  for( int i = n; i < 2*n; i++ ){
    int x; cin >> x;
    tot_cols += x;
 
    adj[i].push_back(sink);
    adj[sink].push_back(i);
 
    capacity[i][sink] = x;
  }
 
  for( int i = 0; i < n; i++ ) for( int j = n; j < 2*n; j++ ){
    adj[i].push_back(j);
    adj[j].push_back(i);
    capacity[i][j] = 1;
 
    cin >> cost[j][i];
    cost[i][j] = -cost[j][i];
  }
 
  vector<int> dist(N), pai(N), inq(N);
 
  auto bellman_ford = [&](){
    fill( dist.begin(), dist.end(), inf );
    fill( pai.begin(), pai.end(), -1 );
    fill( inq.begin(), inq.end(), false );
    dist[source] = 0;
 
    queue<int> fila;
    fila.push(source);
 
    while( !fila.empty() ){
      int u = fila.front();
      fila.pop();
      inq[u] = false;
 
      for( int v : adj[u] ) if( capacity[u][v] > 0 && dist[v] > dist[u] + cost[u][v] ){
        dist[v] = dist[u] + cost[u][v];
        pai[v] = u;
 
        if( !inq[v] ) fila.push(v);
      }
    }
  };
 
  auto min_cost_flow = [&](){
    int flow = 0;
    int cost = 0;
    while(true){
      bellman_ford();
      if( dist[sink] == inf ) break;
 
      int f = inf;
      for( int cur = sink; cur != source; cur = pai[cur] )
        f = min( f, capacity[pai[cur]][cur] );
 
      flow += f;
      cost += f*dist[sink];
 
      for( int cur = sink; cur != source; cur = pai[cur] ){
        capacity[pai[cur]][cur] -= f;
        capacity[cur][pai[cur]] += f;
      }
    }
    return make_pair( flow, cost );
  };
 
  auto [flow, val] = min_cost_flow();
 
  if( flow != tot_cols || flow != tot_rows ){ cout << -1 << endl; return 0; }
  cout << -val << endl;
  vector<string> resp(n, string(n, '.'));
  for( int i = 0; i < n; i++ ) for( int j = n; j < 2*n; j++ ) if( capacity[i][j] == 0 ) resp[i][j - n] = 'X';
  for( auto &s : resp ) cout << s << endl;
}