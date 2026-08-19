#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC target("popcnt")
 
int main(){
  ios::sync_with_stdio(false); cin.tie(NULL);
  int n, k; cin >> n >> k;
  vector<int> v(n);
  int resp = k;
  for( int i = 0; i < n; i++ ){
    for( int j = 0; j < k; j++ ){
      char c; cin >> c;
      v[i] <<= 1;
      if( c == '1' ) v[i]++;
    }
    for( int j = 0; j < i; j++ ) resp = min( resp, __builtin_popcount(v[i]^v[j]) );
  }
  cout << resp << endl;
}