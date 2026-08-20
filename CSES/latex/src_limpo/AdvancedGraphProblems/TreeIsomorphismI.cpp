map<vector<int>, int> mp;
vector<vector<vector<int>>> adj;
int cont = 0;

int converte( vector<int> &v ){
  if( mp[v] == 0 ) mp[v] = ++cont;
  return mp[v];
}

int dfs( int cur, int pai, int t ){
  vector<int> v;
  for( int viz : adj[t][cur] ) if( viz != pai ) v.push_back(dfs( viz, cur, t ) );
  sort( v.begin(), v.end() );
  return converte(v);
}

void solve(){
  mp.clear();
  cont = 0;
  adj.clear();
  int n; cin >> n;
  adj.resize(2, vector<vector<int>>(n));

  for( int i = 0; i < n - 1; i++ ){
    int a, b; cin >> a >> b;
    a--; b--;
    adj[0][a].push_back(b);
    adj[0][b].push_back(a);
  }

  for( int i = 0; i < n - 1; i++ ){
    int a, b; cin >> a >> b;
    a--; b--;
    adj[1][a].push_back(b);
    adj[1][b].push_back(a);
  }

  cout << (( dfs( 0, 0, 0 ) == dfs( 0, 0, 1 ) ) ? "YES" : "NO" ) << endl;
}
