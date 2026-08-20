const int mod = 1e9 + 7;

int main(){
  int n; cin >> n;
  vector<int> v(n);
  for( int &x : v ) cin >> x;

  vector<int> dp(n + 2);
  dp[0] = 1;
  dp[1] = -1;

  map<int, bool> marc;
  for( int i = 0, j = -1; i < n; i++ ){

    while( j + 1 < n && !marc[v[j + 1]] )
      marc[v[++j]] = true;

    dp[i + 1] += dp[i];
    dp[i + 1] %= mod;

    dp[j + 2] -= dp[i];
    dp[j + 2] %= mod;
    marc[v[i]] = false;

    dp[i + 1] = ((dp[i + 1] + dp[i])%mod + mod)%mod;
  }

  cout << dp[n] << endl;
}
