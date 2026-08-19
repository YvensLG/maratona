#include <bits/stdc++.h>
using namespace std;
 
vector<int> z_function( string &s ){
  int n = s.size();
  vector<int> z(n);
  for( int i = 1, l = 0, r = 0; i < n; i++ ){
    if( i < r ) z[i] = min( r - i, z[i - l] );
    while( i + z[i] < n && s[z[i]] == s[i + z[i]] ) z[i]++;
    if( i + z[i] > r ) l = i, r = i + z[i];
  }
  return z;
}
 
int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string s; cin >> s;
  vector<int> z = z_function(s);
  int n = s.size();
  for( int i = 1; i < n; i++ ) if( i + z[i] == n ) cout << i << " ";
  cout << n << endl;
}
