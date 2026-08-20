const int alphabet = 26;
const int mod = 1e9 + 7;

int main(){
  string s; cin >> s;
  int n = s.size();

  auto sum = [&]( int a, int b ){
    return (a + b)%mod;
  };

  vector<vector<int>> last( n, vector<int>(alphabet, -1));
  for( int i = 0; i < n; i++ ){
    if( i > 0 ) last[i] = last[i - 1];
    last[i][s[i] - 'a'] = i;
  }

  vector<int> dp(n);

  for( int j : last.back() ) if( j != -1 ) dp[j] = 1;
  for( int i = n - 1; i >= 0; i-- )
    if( i > 0 ) for( int j : last[i - 1] ) if( j != -1 ) dp[j] = sum( dp[j], dp[i] );

  cout << accumulate(dp.begin(), dp.end(), 0LL)%mod << endl;
}
