#include <bits/stdc++.h>
using namespace std;
 
const int alphabet = 26;
const int mod = 1e9 + 7;
 
class Trie{
private:
  struct Node{
    int output;
    vector<int> adj;
    Node() : output(false) {
      adj.resize(alphabet, -1);
    }
  };
  vector<Node> t;
 
  int create(){
    t.emplace_back();
    return (int)t.size() - 1;
  }
 
  int get_adj( int node, int c ){
    if( t[node].adj[c] == -1 ){ int aux = create(); t[node].adj[c] = aux; }
    return t[node].adj[c];
  }
 
public:
 
  Trie(){ create(); }
 
  void add_string( string &s ){
    int node = 0;
    for( char c : s ) node = get_adj( node, c - 'a' );
    t[node].output = true;
  }
 
  int go( int node, int c ){
    return t[node].adj[c];
  }
 
  bool is_output( int node ){
    return t[node].output;
  }
};
 
int main(){
  string s; cin >> s;
  int n = s.size();
 
  Trie trie;
 
  int m; cin >> m;
  while( m-- ){
    string t; cin >> t;
    trie.add_string(t);
  }
 
  vector<int> dp(n + 1);
  dp[0] = 1;
 
  for( int i = 0; i < n; i++ ){
    for( int j = i, node = 0; j < n; j++ ){
      node = trie.go( node, s[j] - 'a' );
      if( node == -1 ) break;
      if( trie.is_output(node) ){
        dp[j + 1] += dp[i];
        dp[j + 1] %= mod;
      }
    }
  }
 
  cout << dp.back() << endl;
}