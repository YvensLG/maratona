#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
class Treap{
private:
  struct Node{
    ll sum, val; int prior, lazy, sub;
    Node *l = nullptr, *r = nullptr;
    Node( int x = 0 ) : sum(x), val(x), prior(rng()), sub(1), lazy(0) {}
  };
  vector<Node> v;
  Node *root = nullptr;
 
public:
  int get_sub( Node* x ){ return (( x ) ? x->sub : 0 ); }
  ll get_sum( Node* x ){ return (( x ) ? x->sum : 0 ); }
  Node* update( Node* x ){
    x->sub = get_sub(x->l) + get_sub(x->r) + 1;
    x->sum = get_sum(x->l) + get_sum(x->r) + x->val;
    return x;
  }
 
  void refresh( Node* x ){
    if( x == nullptr || x->lazy == 0 ) return;
    x->lazy = 0;
    swap( x->l, x->r );
    if( x->l ) x->l->lazy ^= 1;
    if( x->r ) x->r->lazy ^= 1;
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
 
  pair<Node*, Node*> split( Node* root, int k ){
    refresh( root );
    if( root == nullptr ) return make_pair( nullptr, nullptr );
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
    b->lazy ^= 1; refresh(b);
    root = merge( merge( a, b ), c );
  }
 
  ll query( int l, int r ){
    auto [a, b, c] = split( root, l, r );
    ll resp = get_sum(b);
    root = merge( merge( a, b ), c );
    return resp;
  }
 
  Treap( vector<int>& xs ){
    v.resize(xs.size());
    for( int i = 0; i < xs.size(); i++ ){
      v[i] = Node(xs[i]);
      root = merge( root, &v[i] );
    }
  }
};
 
int main(){
  int n, q; cin >> n >> q;
  vector<int> v(n);
  for( int &x : v ) cin >> x;
 
  Treap treap(v);
 
  while( q-- ){
    int t, l, r; cin >> t >> l >> r;
    if( t == 1 ) treap.reverse( l, r );
    else cout << treap.query( l, r ) << endl;
  }
 
}