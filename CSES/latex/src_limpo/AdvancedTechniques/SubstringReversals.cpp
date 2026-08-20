mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Treap{
private:
  struct Node{
    char c; int prior, sub, lazy = 0;
    Node *l = nullptr, *r = nullptr;
    Node( char c = '#' ) : c(c), prior(rng()), sub(1), lazy(0) {}
  };
  vector<Node> v;
  Node *root = nullptr;
public:
  int get_sub( Node *x ){ return (( x != nullptr ) ? x->sub : 0 ); }
  Node* update( Node *x ){ x->sub = get_sub(x->l) + get_sub(x->r) + 1; return x; }

  void print( Node *x ){
    if( x == nullptr ) return;
    refresh( x );
    print( x->l );
    cout << x->c;
    print( x->r );
  }

  void print(){ print( root ); cout << endl; }

  void refresh( Node *x ){
    if( x == nullptr || x->lazy == 0 ) return;
    x->lazy = 0;
    swap( x->l, x->r );
    if( x->l != nullptr ) x->l->lazy ^= 1;
    if( x->r != nullptr ) x->r->lazy ^= 1;
  }

  Node* merge( Node *a, Node *b ){
    refresh(a); refresh(b);

    if( a == nullptr ) return b;
    if( b == nullptr ) return a;

    if( a->prior > b->prior ){
      a->r = merge( a->r, b );
      return update(a);
    }
    else{
      b->l = merge( a, b->l );
      return update(b);
    }
  }

  pair<Node*, Node*> split( Node *root, int k ){
    if( root == nullptr ) return make_pair( nullptr, nullptr );
    refresh( root );
    if( k <= get_sub(root->l) ){
      auto [a, b] = split( root->l, k );
      root->l = b;
      return make_pair(a, update(root));
    }
    else{
      auto [a, b] = split( root->r, k - get_sub(root->l) - 1 );
      root->r = a;
      return make_pair(update(root), b);
    }
  }

  tuple<Node*, Node*, Node*> split( Node* root, int l, int r ){
    auto [a, b] = split( root, r );
    auto [c, d] = split( a, l - 1 );
    return make_tuple( c, d, b );
  }

  void reverse( int l, int r ){
    auto [a, b, c] = split( root, l, r );
    b->lazy ^= 1;
    refresh( b );
    root = merge( merge( a, b ), c );
  }

  Treap( string &s ){
    v.resize(s.size());
    for( int i = 0; i < v.size(); i++ ){
      v[i] = Node(s[i]);
      root = merge( root, &v[i] );
    }
  }
};

int main(){
  int n, q; cin >> n >> q;
  string s; cin >> s;
  Treap treap( s );

  while( q-- ){
    int l, r; cin >> l >> r;
    treap.reverse( l, r );
  }
  treap.print();
}
