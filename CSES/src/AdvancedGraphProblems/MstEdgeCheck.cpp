#include <bits/stdc++.h>
using namespace std;
 
using quadrupla = tuple<int, int, int, int>;
 
int main(){
  int n, m; cin >> n >> m;
  vector<quadrupla> arestas;
  for( int i = 0; i < m; i++ ){
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    arestas.emplace_back( c, a, b, i );
  }
  sort( arestas.begin(), arestas.end() );
 
  vector<int> pai(n); iota( pai.begin(), pai.end(), 0 );
 
  function<int(int)> find = [&]( int a ){ return (( pai[a] == a ) ? a : pai[a] = find(pai[a])); };
  auto join = [&]( int a, int b ){
    pai[find(a)] = find(b);
  };
 
  vector<bool> resp(m);
  for( int l = 0, r = 0; l < m; l = r ){
    while( (r < m) && (get<0>(arestas[r]) == get<0>(arestas[l])) ) r++;
    for( int i = l; i < r; i++ ){
      auto [c, a, b, id] = arestas[i];
      if( find(a) != find(b) ) resp[id] = true;
    }
    for( int i = l; i < r; i++ ) join( get<1>(arestas[i]), get<2>(arestas[i]) );
  }
  for( bool x : resp ) cout << (( x ) ? "YES" : "NO" ) << endl;
}