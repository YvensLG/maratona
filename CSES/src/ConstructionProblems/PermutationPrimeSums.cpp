#include <bits/stdc++.h>
using namespace std;
 
// teorema: existe ao menos um primo p entre n e 2*n
 
int main(){
  int n; cin >> n;
  // crivo de eratostenes
  vector<bool> primo(2*n + 1, true);
  for( int i = 2; i < primo.size(); i++ ) if( primo[i] )
    for( int j = 2*i; j < primo.size(); j += i ) primo[j] = false;
 
  vector<int> a, b;
 
  while( n > 0 ){
    int p = n;
    while( !primo[n + p] ) p--;
    for( int j = p; j <= n; j++ ) a.push_back(j), b.push_back(n + p - j);
    n = p - 1;
  }
 
  for( int x : a ) cout << x << " "; cout << endl;
  for( int x : b ) cout << x << " "; cout << endl;
 
}