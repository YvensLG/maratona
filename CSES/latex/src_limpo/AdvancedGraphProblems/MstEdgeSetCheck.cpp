using quadrupla = tuple<int, int, int, int>;

class unionFind{
private:
  vector<int> pai, tam;
  stack<int> pilha;
  int find( int a, int t ){
    if( a == pai[a] ) return a;
    if( t == 0 ) return find(pai[a], t);
    return pai[a] = find(pai[a], t);
  }
public:
  unionFind( int n ) { pai.resize(n); iota( pai.begin(), pai.end(), 0 ); tam.resize(n, 1); }

  void rollback(){
    int id = pilha.top(); pilha.pop();
    if( id != -1 ){ tam[pai[id]] -= tam[id]; pai[id] = id; }
  }

  void join( int a, int b, int t ){
    a = find(a, t);
    b = find(b, t);
    if( a == b ){ pilha.push(-1); return; }
    if( tam[a] < tam[b] ) swap( a, b );
    pai[b] = a;
    pilha.push(b);
  }

  bool check( int a, int b ){ return find(a, 0) == find(b, 0); }
};

int main(){
  int n, m, q; cin >> n >> m >> q;

  unionFind union_find(n);

  vector<quadrupla> arestas;
  for( int i = 0; i < m; i++ ){
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    arestas.emplace_back( c, a, b, i );
  }
  sort( arestas.begin(), arestas.end() );

  vector<vector<int>> queries(m);

  for( int i = 0; i < q; i++ ){
    int k; cin >> k;
    while( k-- ){
      int x; cin >> x;
      queries[--x].push_back(i);
    }
  }

  vector<bool> resp(q, true);
  vector<vector<int>> cur_edges(q);

  for( int l = 0, r = 0; l < m; l = r ){
    while( (r < m) && (get<0>(arestas[r]) == get<0>(arestas[l])) ) r++;
    for( int i = l; i < r; i++ ) for( int x : queries[get<3>(arestas[i])] ) cur_edges[x].clear();

    vector<int> id_queries;
    for( int i = l; i < r; i++ ){
      auto [c, a, b, id] = arestas[i];
      for( int x : queries[id] ){
        cur_edges[x].push_back(i);
        if( cur_edges[x].size() == 1 ) id_queries.push_back(x);
      }
    }

    for( int x : id_queries ) if( resp[x] ){
      bool ok = true;
      int cont = 0;
      for( int i : cur_edges[x] ){
        auto [c, a, b, id] = arestas[i];
        if( union_find.check( a, b ) ){ ok = false; break; }
        cont++;
        union_find.join( a, b, 0 );
      }
      while( cont-- ) union_find.rollback();

      resp[x] = resp[x]&&ok;
    }

    for( int i = l; i < r; i++ ) union_find.join( get<1>(arestas[i]), get<2>(arestas[i]), 1 );
  }

  for( bool x : resp ) cout << (( x ) ? "YES" : "NO" ) << endl;
}
