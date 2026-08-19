#include <bits/stdc++.h>
using namespace std;
 
#define bug(x) cout << #x << " " << x << endl;
 
using ll = long long;
 
const int mod = 1e9 + 7;
const int base = 43;
const int maxn = 2e5 + 10;
 
struct Node{
  ll hash, inv_hash, pot;
  Node( char c = 'a' ) : pot(base), hash(c - 'a'), inv_hash(c - 'a') {}
 
  Node operator + ( Node n ){
    Node resp;
    resp.hash = (hash + pot*n.hash)%mod;
    resp.inv_hash = (n.inv_hash + n.pot*inv_hash)%mod;
    resp.pot = (pot*n.pot)%mod;
 
    return resp;
  }
} seg[4*maxn];
 
void build( int pos, int ini, int fim, string &s ){
 
  if( ini == fim ){
    seg[pos] = Node( s[ini] );
    return;
  }
  int l = 2*pos, r = 2*pos + 1, mid = (ini + fim)/2;
  build( l, ini, mid, s); build( r, mid + 1, fim, s );
  seg[pos] = seg[l] + seg[r];
}
 
void update( int pos, int ini, int fim, int id, char c ){
  if( ini > id || id > fim ) return;
  if( ini == fim ){
    seg[pos] = Node(c);
    return;
  }
  int l = 2*pos, r = 2*pos + 1, mid = (ini + fim)/2;
  update( l, ini, mid, id, c ); update( r, mid + 1, fim, id, c );
  seg[pos] = seg[l] + seg[r];
}
 
Node query( int pos, int ini, int fim, int ki, int kf ){
  if( ki > fim || ini > kf ) return seg[0];
  if( ki <= ini && fim <= kf ) return seg[pos];
  int l = 2*pos, r = 2*pos + 1, mid = (ini + fim)/2;
  return query( l, ini, mid, ki, kf ) + query( r, mid + 1, fim, ki, kf );
}
 
void update( int id, char c, int n ){
  update( 1, 0, n - 1, id, c );
}
 
bool query( int l, int r, int n ){
  Node x = query( 1, 0, n - 1, l, r );
  return x.hash == x.inv_hash;
}
 
 
int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, q; cin >> n >> q;
  string s; cin >> s;
 
  build( 1, 0, n - 1, s );
  seg[0].pot = 1;
 
  while( q-- ){
    int t; cin >> t;
    if( t == 1 ){
      int id; char c; cin >> id >> c;
      update( id - 1, c, n );
    }
    else{
      int l, r; cin >> l >> r;
      cout << (( query( l - 1, r - 1, n ) ) ? "YES" : "NO") << '\n';
    }
  }
}
