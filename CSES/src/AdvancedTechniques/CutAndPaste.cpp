#include <bits/stdc++.h>
using namespace std;
 
struct Node{
  char c; int val, tam = 0;
  Node *r = nullptr, *l = nullptr;
  Node( char c = 0, int val = 0 ) : c(c), val(val), tam(1) {}
};
 
int tam( Node* x ){ return (( x == nullptr ) ? 0 : x->tam ); }
 
Node* merge( Node *a, Node *b ){
  if( a == nullptr ) return b;
  if( b == nullptr ) return a;
 
 
  if( a->val > b->val ){
    a->r = merge( a->r, b );
    a->tam = tam(a->l) + tam(a->r) + 1;
    return a;
  }
  else{
    b->l = merge( a, b->l );
    b->tam = tam(b->l) + tam(b->r) + 1;
    return b;
  }
}
 
 
void print( Node *root ){
  if( root == nullptr ) return;
  print( root->l );
  cout << root->c;
  print( root->r );
}
 
pair<Node*, Node*> split( Node* root, int k ){
  if( root == nullptr ) return make_pair( nullptr, nullptr );
  if( k <= tam(root->l) ){
    auto [a, b] = split( root->l, k );
    root->l = b;
    root->tam = tam(root->l) + tam(root->r) + 1;
    return make_pair( a, root );
  }
  else{
    auto [a, b] = split( root->r, k - tam(root->l) - 1 );
    root->r = a;
    root->tam = tam(root->l) + tam(root->r) + 1;
    return make_pair( root, b );
  }
}
 
tuple<Node*, Node*, Node*> split( Node* root, int l, int r ){
  auto [a, b] = split( root, r );
  auto [c, d] = split( a, l - 1 );
  return make_tuple(c, d, b);
}
 
 
int main(){
  int n, m; cin >> n >> m;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  vector<Node> v(n);
 
  Node *root = nullptr;
  for( int i = 0; i < n; i++ ){
    char c; cin >> c;
    v[i] = Node( c, rng() );
  }
 
  for( auto& x : v ) root = merge( root, &x );
 
  while( m-- ){
    int l, r; cin >> l >> r;
    auto [a, b, c] = split( root, l, r );
 
    root = merge( merge( a, c ), b );
  }
 
  print(root);
}