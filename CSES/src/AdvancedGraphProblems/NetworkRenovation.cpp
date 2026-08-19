#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n; cin >> n;
  vector<vector<int>> adj(n);
  for( int i = 0; i < n - 1; i++ ){
    int a, b; cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> folhas;
  function<void(int, int)> dfs = [&]( int cur, int pai ){
    for( int viz : adj[cur] ) if( viz != pai ) dfs( viz, cur );
    if( adj[cur].size() == 1 ) folhas.push_back(cur);
  };
 
  dfs( 0, 0 );
 
  int k = folhas.size();
  cout << (k + 1)/2 << endl;
  for( int i = 0; i < k/2; i++ )
    cout << folhas[i] + 1 << " " << folhas[i + k/2] + 1 << endl;
  if( k%2 ) cout << folhas[0] + 1 << " " << folhas.back() + 1 << endl;
}