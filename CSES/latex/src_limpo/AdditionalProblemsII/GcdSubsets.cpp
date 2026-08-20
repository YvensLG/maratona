using ll = long long;

const ll mod = 1e9 + 7;

ll pot( ll b, ll e, ll mod ){
  ll resp = 1;
  for(; e > 0; e >>= 1 ){
    if( e&1 ) resp = (resp*b)%mod;
    b = (b*b)%mod;
  }
  return resp;
}

int main(){
  int n; cin >> n;
  vector<ll> cont(n + 1);
  for( int i = 0; i < n; i++ ){
    int x; cin >> x;
    for( int j = 1; j*j <= x; j++ ) if( x%j == 0 ){
      cont[j]++;
      if( j*j != x ) cont[x/j]++;
    }
  }

  for( int i = n; i >= 1; i-- ){
    cont[i] = (pot( 2, cont[i], mod ) - 1 + mod)%mod;
    for( int j = 2*i; j <= n; j += i ) cont[i] = (cont[i] - cont[j] + mod)%mod;
  }

  for( int i = 1; i <= n; i++ ) cout << cont[i] << " "; cout << endl;
}
