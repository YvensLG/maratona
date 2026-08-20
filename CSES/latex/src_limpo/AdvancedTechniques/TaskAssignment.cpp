const int maxn = 400 + 2;
const int inf = 2e9;

int cost[maxn][maxn], capacity[maxn][maxn], dist[maxn], pai[maxn];
vector<int> adj[maxn];

void dijkstra( int source ){
  fill( dist, dist + maxn, inf );
  fill( pai, pai + maxn, -1 );

  set<pair<int, int>> s;
  s.insert({ 0, source });
  dist[source] = 0;

  while( !s.empty() ){
    int cur = s.begin()->second; s.erase(s.begin());
    for( int viz : adj[cur] ) if( capacity[cur][viz] && dist[viz] > dist[cur] + cost[cur][viz] ){
      s.erase({ dist[viz], viz });
      dist[viz] = dist[cur] + cost[cur][viz];
      s.insert({ dist[viz], viz });

      pai[viz] = cur;
    }
  }
}

int min_cost_flow( int n ){
  int source = 2*n;
  int sink = 2*n + 1;

  for( int i = 0; i < n; i++ ){
    capacity[source][i] = 1;
    adj[source].push_back(i);
    adj[i].push_back(source);
  }

  for( int i = n; i < 2*n; i++ ){
    capacity[i][sink] = 1;
    adj[i].push_back(sink);
    adj[sink].push_back(i);
  }

  int flow = 0, cost = 0;
  while( flow < n ){
    dijkstra(source);

    int new_flow = n - flow;
    for( int cur = sink; cur != source; cur = pai[cur] )
      new_flow = min( new_flow, capacity[pai[cur]][cur] );

    flow += new_flow;
    cost += new_flow*dist[sink];

    for( int cur = sink; cur != source; cur = pai[cur] ){
      capacity[pai[cur]][cur] -= new_flow;
      capacity[cur][pai[cur]] += new_flow;
    }
  }
  return cost;
}

int main(){
  int n; cin >> n;

  for( int i = 0; i < n; i++ )
    for( int j = n; j < 2*n; j++ ){
      cin >> cost[i][j];
      cost[j][i] = -cost[i][j];

      capacity[i][j] = 1;

      adj[i].push_back(j);
      adj[j].push_back(i);
    }

  int min_cost = min_cost_flow(n);

  cout << min_cost << endl;
  for( int i = 0; i < n; i++ )
    for( int j = n; j < 2*n; j++ ) if( capacity[i][j] == 0 )
        cout << i + 1 << " " << j - n + 1 << endl;
}
