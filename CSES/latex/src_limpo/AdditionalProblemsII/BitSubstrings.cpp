using ll = long long;
using cd = complex<long double>;

const double PI = acos(-1);

void FFT( vector<cd> &a, bool invert ){
  int n = a.size();
  for( int i = 1, j = 0; i < n; i++ ){
    int bit = (n>>1);
    for(; j&bit; bit >>= 1 ) j ^= bit;
    j ^= bit;

    if( i < j ) swap( a[i], a[j] );
  }

  for( int len = 2; len <= n; len <<= 1 ){
    double ang = ((invert) ? -1.0 : 1.0 )*2*PI/len;
    cd wlen( cos(ang), sin(ang) );
    for( int i = 0; i < n; i += len ){
      cd w(1);
      for( int j = 0; j < len/2; j++ ){
        cd u = a[i + j], v = a[i + j + len/2]*w;
        a[i + j] = u + v;
        a[i + j + len/2] = u - v;
        w *= wlen;
      }
    }
  }

  if( invert ) for( auto &x : a ) x /= n;
}

vector<ll> mult( vector<int> &a, vector<int> &b ){
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while( n < a.size() + b.size() ) n <<= 1;
  fa.resize(n); fb.resize(n);

  FFT( fa, false ); FFT( fb, false );
  for( int i = 0; i < n; i++ ) fa[i] *= fb[i];
  FFT( fa, true );

  vector<ll> resp(n);
  for( int i = 0; i < n; i++ ) resp[i] = round(fa[i].real());
  return resp;
}

int main(){

  string s; cin >> s;
  int n = s.size();

  vector<int> a(n + 1), b(n + 1);

  ll resp0 = 0;

  a[0] = 1;
  for( int i = 0, sum = 0, cont0 = 0; i < n; i++ ){
    sum += s[i] - '0';
    a[sum]++;

    if( s[i] == '0' ) cont0++;
    else cont0 = 0;

    resp0 += cont0;
  }

  for( int i = 0; i <= n; i++ ) b[i] = a[n - i];

  vector<ll> v = mult( a, b );

  cout << resp0 << " ";
  for( int i = n + 1; i <= 2*n; i++ ) cout << v[i] << " "; cout << endl;
}
