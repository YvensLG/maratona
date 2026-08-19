#include <bits/stdc++.h>
using namespace std;
 
void solveTest(){
  int n, k; cin >> n >> k;
  if( k*k < n ){ cout << "IMPOSSIBLE" << endl; return; }
  for( int i = 1; i <= ((n + k - 1)/k); i++ ) for( int j = min(i*k, n); j > (i - 1)*k; j-- ) cout << j << " ";
  cout << endl;
}
 
int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while( t-- ) solveTest();
}