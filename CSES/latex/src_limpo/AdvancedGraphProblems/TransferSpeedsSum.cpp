using ll = long long;

int main(){
  int n; cin >> n;
  vector<tuple<int, int, int>> arestas;
  for( int i = 0; i < n - 1; i++ ){
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    arestas.emplace_back(c, a, b);
  }

  sort( arestas.rbegin(), arestas.rend() );

  vector<int> pai(n), tam(n, 1); iota( pai.begin(), pai.end(), 0 );

  function<int(int)> find = [&]( int a ){ return (( a == pai[a] ) ? a : pai[a] = find(pai[a])); };
  auto join = [&]( int a, int b ){
    a = find(a); b = find(b);
    if( tam[a] < tam[b] ) swap( a, b );
    pai[b] = a;
    tam[a] += tam[b];
  };

  ll resp = 0;
  for( auto [c, a, b] : arestas ){
    resp += 1LL*tam[find(a)]*tam[find(b)]*c;
    join( a, b );
  }

  cout << resp << endl;
}
