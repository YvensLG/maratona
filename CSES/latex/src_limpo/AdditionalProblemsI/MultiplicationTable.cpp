using ll = long long;

const ll inf = 1e12;

bool check( ll n, ll k ){
  ll cont = 0;
  for( int i = 1; i <= n; i++ ) cont += min( n, k/i );
  return cont >= (n*n + 1)/2;
}

ll bs( int n ){
  ll l = 0, r = 1LL*n*n;
  while( l < r ){
    ll mid = ( l + r )/2;
    if( check( n, mid ) ) r = mid;
    else l = mid + 1;
  }
  return r;
}

int main(){
  int n; cin >> n;
  cout << bs(n) << endl;
}
