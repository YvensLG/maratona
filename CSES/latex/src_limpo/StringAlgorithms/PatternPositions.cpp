using pii = pair<int, int>;

const int alphabet = 26;

class AhoCorasick{
private:
  struct Node{
    int suffix_link, output, pai, pai_ch;
    vector<int> go, adj;

    Node( int pai = 0, int pai_ch = 0 ) : pai(pai), pai_ch(pai_ch), suffix_link(-1), output(false){
      go = adj = vector<int>( alphabet, -1 );
    };
  };
  vector<Node> t;

  int create( int pai, int pai_ch ){
    t.emplace_back( pai, pai_ch );
    return (int)t.size() - 1;
  }

  int get_adj( int node, int c ){
    if( t[node].adj[c] == -1 ){ int aux = create( node, c ); t[node].adj[c] = aux; }
    return t[node].adj[c];
  }
public:
  AhoCorasick(){ create(0, 0); }

  int add_string( string &s ){
    int node = 0;
    for( char c : s ) node = get_adj( node, c - 'a' );
    t[node].output = true;
    return node;
  }

  int suffix_link( int node ){
    if( t[node].suffix_link != -1 ) return t[node].suffix_link;
    if( node == 0 || t[node].pai == 0 ) return t[node].suffix_link = 0;
    return t[node].suffix_link = go( suffix_link(t[node].pai), t[node].pai_ch );
  }

  int go( int node, int c ){
    if( t[node].go[c] != -1 ) return t[node].go[c];
    if( t[node].adj[c] != -1 ) return t[node].go[c] = t[node].adj[c];
    return t[node].go[c] = (( node == 0 ) ? 0 : go( suffix_link(node), c ) );
  }

  int size(){ return t.size(); }
};

int main(){
  string s; cin >> s;
  int q; cin >> q;

  AhoCorasick aho;

  vector<pii> queries(q);

  for( int i = 0; i < q; i++ ){
    string t; cin >> t;
    queries[i] = pii(aho.add_string(t), t.size());
  }

  vector<int> marc(aho.size(), -1e9 );

  int node = 0;
  for( int i = 0; i < s.size(); i++ ){
    node = aho.go( node, s[i] - 'a' );
    for( int cur = node; marc[cur] == -1e9; cur = aho.suffix_link(cur) )
      marc[cur] = i;
  }

  for( auto [id, tam] : queries ) cout << max( -1, marc[id] - tam + 2 ) << endl;
}
