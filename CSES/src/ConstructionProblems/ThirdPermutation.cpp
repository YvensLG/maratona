#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n; cin >> n;
  vector<int> a(n), b(n), pos_a(n);
  for( int i = 0; i < n; i++ ){
    cin >> a[i];
    pos_a[--a[i]] = i;
  }
  for( int i = 0; i < n;i ++ ){
    cin >> b[i]; b[i]--;
  }
 
  if( n == 2 ){ cout << "IMPOSSIBLE" << endl; return 0; }
 
  set<int> all(a.begin(), a.end()), free;
 
  auto find = [&]( set<int>& s, int x ){ return s.find(x) != s.end(); };
 
  vector<int> c(n, -1);
 
  for( int i = 0; i < n; i++ ) if( a[i] == b[pos_a[b[i]]] && i < pos_a[b[i]] ){
    bool b1 = find( all, a[i] ), b2 = find( all, b[i] );
    all.erase(a[i]); all.erase(b[i]);
 
    set<int> &s = ((free.empty()) ? all : free);
 
    int v1 = *s.begin(); s.erase(s.begin());
    int v2 = *s.begin(); s.erase(s.begin());
 
    if( b1 ) free.insert(a[i]);
    if( b2 ) free.insert(b[i]);
    c[i] = v1; c[pos_a[b[i]]] = v2;
  }
 
  for( int i = 0; i < n; i++ ) if( c[i] == -1 ){
    int val = b[pos_a[b[i]]];
    if( find( all, val ) ){ c[i] = val; all.erase(val); }
    else{ c[i] = *free.begin(); free.erase(free.begin()); }
  }
 
  for( int x : c ) cout << x + 1 << " "; cout << endl;
}