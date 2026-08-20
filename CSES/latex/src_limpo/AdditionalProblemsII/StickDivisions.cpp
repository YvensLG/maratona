int main(){
  ll x, n; cin >> x >> n;
  multiset<ll> s;
  while( n-- ){ int v; cin >> v; s.insert(v); }
  ll resp = 0;
  while( s.size() > 1 ){
    ll a = *s.begin(); s.erase(s.begin());
    ll b = *s.begin(); s.erase(s.begin());
    resp += a + b;
    s.insert(a + b);
  }
  cout << resp << endl;
}
