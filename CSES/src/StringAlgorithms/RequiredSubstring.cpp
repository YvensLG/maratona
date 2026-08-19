#include <bits/stdc++.h>
using namespace std;
 
const int alphabet = 26;
const int mod = 1e9 + 7;
 
vector<int> prefix_function( string &s ){
  int n = s.size();
  vector<int> pi(n);
  for( int i = 1; i < n; i++ ){
    int j = pi[i - 1];
    while( j > 0 && s[i] != s[j] ) j = pi[j - 1];
    pi[i] = j + (int)(s[i] == s[j]);
  }
  return pi;
}
 
vector<vector<int>> build_automaton( string &s ){
  s += '#';
  vector<int> pi = prefix_function(s);
 
  int n = s.size();
  vector<vector<int>> aut( n, vector<int>(alphabet));
  for( int i = 0; i < n; i++ ){
    for( int c = 0; c < alphabet; c++ ){
      if( i > 0 && s[i] - 'A' != c ) aut[i][c] = aut[pi[i - 1]][c];
      else aut[i][c] = i + (int)(s[i] - 'A' == c);
    }
  }
  return aut;
}
 
int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  string s; cin >> s;
  vector<vector<int>> aut = build_automaton(s);
  vector<vector<int>> dp(2, vector<int>(s.size()));
 
  dp[0][0] = 1;
  for( int i = 0; i < n; i++ ){
    vector<vector<int>> next_dp(2, vector<int>(s.size()));
    for( int state = 0; state < s.size(); state++ ){
      for( int c = 0; c < alphabet; c++ ){
        int new_state = aut[state][c];
        next_dp[1][new_state] += dp[1][state];
        next_dp[1][new_state] %= mod;
 
        next_dp[(new_state == (int)s.size() - 1)][new_state] += dp[0][state];
        next_dp[(new_state == (int)s.size() - 1)][new_state] %= mod;
      }
    }
    swap( dp, next_dp );
  }
 
  cout << accumulate( dp[1].begin(), dp[1].end(), 0LL )%mod << endl;
}