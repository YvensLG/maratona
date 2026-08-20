#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n; cin >> n;
  int source = 2*n, sink = 2*n + 1;
 
  int N = 2*n + 2;
 
  int total_rows = 0, total_cols = 0;
 
  vector<vector<int>> capacity( N, vector<int>(N)), adj(N);
  for( int i = 0; i < n; i++ ){
    int x; cin >> x;
    adj[i].push_back(source);
    adj[source].push_back(i);
 
    capacity[source][i] = x;
 
    total_rows += x;
  }
 
  for( int i = n; i < 2*n; i++ ){
    int x; cin >> x;
    adj[i].push_back(sink);
    adj[sink].push_back(i);
 
    capacity[i][sink] = x;
 
    total_cols += x;
  }
 
  for( int i = 0; i < n; i++ )
    for( int j = n; j < 2*n; j++ ){
        adj[i].push_back(j); adj[j].push_back(i);
        capacity[i][j] = 1;
    }
 
  vector<int> pai(N);
 
  auto bfs = [&](){
    queue<pair<int, int>> fila;
 
    fill( pai.begin(), pai.end(), -1 );
 
    fila.push({ N, source });
    while( !fila.empty() ){
      auto [flow, cur] = fila.front(); fila.pop();
      if( cur == sink ) return flow;
 
      for( int viz : adj[cur] ) if( capacity[cur][viz] && pai[viz] == -1 ){
        fila.push({ min( flow, capacity[cur][viz]), viz });
        pai[viz] = cur;
      }
    }
    return 0;
  };
 
  int flow = 0;
  for( int f = bfs(); f > 0; f = bfs() ){
    flow += f;
    for( int cur = sink; cur != source; cur = pai[cur] ){
      capacity[pai[cur]][cur] -= f;
      capacity[cur][pai[cur]] += f;
    }
  }
 
  if( flow != total_cols || total_cols != total_rows ){ cout << -1 << endl; return 0; }
 
  vector<string> resp(n, string(n, '.'));
  for( int i = 0; i < n; i++ ) for( int j = n; j < 2*n; j++ ) if( capacity[i][j] == 0 ) resp[i][j - n] = 'X';
 
  for( string &s : resp ) cout << s << endl;
 
}
