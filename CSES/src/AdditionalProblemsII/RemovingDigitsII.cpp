#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define bug(x) cout << #x << " " << x << endl;
 
const int logn = 20;
 
ll dp[logn][10][10];
int val[logn][10][10];
 
void init(){
  for( int m = 0; m < 10; m++ ) for( int x = 0; x < 10; x++ ){
    dp[1][m][x] = 1;
    val[1][m][x] = (10 + x - max(m, x))%10;
    if( !val[1][m][x] && m > 0 ){
      dp[1][m][x]++;
      val[1][m][x] = (10 - m)%10;
    }
  }
  for( int k = 2; k < logn; k++ ){
    for( int m = 0; m < 10; m++ ){
      dp[k][m][0] = dp[k - 1][m][0];
      val[k][m][0] = val[k - 1][m][0];
      for( int x = 1; x < 10; x++ ){
        val[k][m][x] = x;
        for( int i = 9; i >= 0; i-- ){
          dp[k][m][x] += dp[k - 1][max(m, i)][val[k][m][x]];
          val[k][m][x] = val[k - 1][max(m, i)][val[k][m][x]];
        }
      }
    }
  }
 
  // 10^k - 10 + x
}
 
int main(){
  init();
  ll x; cin >> x;
  ll resp = 0;
  if( x == 1e18 ){ resp++; x--; }
  int unit = x%10;
  for( ll i = 2, pot = 10; resp == 0 || unit != 0; i++, pot *= 10 ){
 
    for( int j = (x%(pot*10) - x%pot)/pot; j >= 0; j--, x -= pot ){
 
      ll maxi = 0;
      for( ll p = pot; p <= 1e17; p *= 10 ) maxi = max( maxi, (x%(p*10) - x%p)/p);
 
      resp += dp[i - 1][maxi][unit];
      unit = val[i - 1][maxi][unit];
    }
  }
  if( unit ) resp++;
  cout << resp << endl;
}