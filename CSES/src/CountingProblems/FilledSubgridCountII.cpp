#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main(){
  ios::sync_with_stdio(false); cin.tie(NULL);
  int n, k; cin >> n >> k;
  vector<int> h(n);
  vector<string> mat(n);
  vector<ll> resp(k);
 
  for( int i = 0; i < n; i++ ){
    cin >> mat[i];
 
    stack<pair<int, int>> pilha; // stack monotonica crescente -> ( altura, comprimento )
    int area = 0;
    for( int j = 0; j < n; j++ ){
      if( i && mat[i - 1][j] == mat[i][j] ) h[j]++;
      else h[j] = 1;
 
      if( j && mat[i][j] != mat[i][j - 1] ){
        area = 0;
        while( !pilha.empty() ) pilha.pop();
      }
 
      int lenght = 1;
      area += h[j];
 
      while( !pilha.empty() && pilha.top().first >= h[j] ){
        auto [H, L] = pilha.top();
        pilha.pop();
 
        area -= (H - h[j])*L;
        lenght += L;
      }
 
      pilha.push({ h[j], lenght });
 
      resp[mat[i][j] - 'A'] += area;
    }
  }
 
  for( int i = 0; i < k; i++ ) cout << resp[i] << endl;
}