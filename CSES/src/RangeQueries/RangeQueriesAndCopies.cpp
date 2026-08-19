#include <bits/stdc++.h>
using namespace std; 
 
using ll = long long;
 
class PersistentSegmentTree{
private:
  ll min_id, max_id;
 
  struct Node{
    ll val; int l, r;
    Node() : val(0), l(0), r(0) {}
  };
  vector<Node> seg;
 
  int create(){
    seg.emplace_back();
    return seg.size() - 1;
  }
 
  int l( int pos ){
    if( seg[pos].l == 0 ){ int aux = create(); seg[pos].l = aux; }
    return seg[pos].l;
  }
 
  int r( int pos ){
    if( seg[pos].r == 0 ){ int aux = create(); seg[pos].r = aux; }
    return seg[pos].r;
  }
 
  int update( int pos, ll ini, ll fim, ll id, ll val ){
    int novo = create();
    if( ini == fim ){ seg[novo].val = val; return novo; }
 
    l(pos); r(pos);
    ll mid = (ini + fim)>>1;
    if( id <= mid ){
      seg[novo].l = update( l(pos), ini, mid, id, val );
      seg[novo].r = seg[pos].r;
    }
    else{
      seg[novo].r = update( r(pos), mid + 1, fim, id, val );
      seg[novo].l = seg[pos].l;
    }
 
    seg[novo].val = seg[seg[novo].l].val + seg[seg[novo].r].val;
    return novo;
  }
 
  ll query( int pos, ll ini, ll fim, ll ki, ll kf ){
    if( pos == 0 || ki > fim || ini > kf ) return 0;
    if( ki <= ini && fim <= kf ) return seg[pos].val;
    ll mid = (ini + fim)>>1;
    return query( seg[pos].l, ini, mid, ki, kf ) + query( seg[pos].r, mid + 1, fim, ki, kf );
  }
public:
  PersistentSegmentTree( ll min_id, ll max_id ) : min_id(min_id), max_id(max_id){ create(); create(); }
 
  int update( int root, ll id, ll val ){ return update( root, min_id, max_id, id, val ); }
  ll query( int root, ll l, ll r ){ return query( root, min_id, max_id, l, r ); }
};
 
int main(){
    int n, q; cin >> n >> q; 
    PersistentSegmentTree seg( 0, n - 1 ); 
    vector<int> root(1, 1);
    
    for( int i = 0; i < n; i++ ){
        int x; cin >> x; 
        root[0] = seg.update( root[0], i, x ); 
    }
    
    while( q-- ){
        int t; cin >> t; 
        if( t == 1 ){
            int ver, id, x; cin >> ver >> id >> x; 
            ver--; id--; 
            root[ver] = seg.update( root[ver], id, x ); 
        }
        if( t == 2 ){
            int ver, l, r; cin >> ver >> l >> r; 
            ver--; l--; r--; 
            cout << seg.query( root[ver], l, r ) << endl;
        }
        if( t == 3 ){
            int ver; cin >> ver; 
            ver--; 
            root.push_back(root[ver]);
        }
    }
 
}