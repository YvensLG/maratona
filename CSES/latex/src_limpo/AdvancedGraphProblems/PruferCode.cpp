int main(){
  int n; cin >> n;
  vector<int> grau(n), v(n - 2);
  for( int &x : v ){ cin >> x; grau[--x]++; }
  set<int> s;
  for( int i = 0; i < n; i++ ) if( grau[i] == 0 ) s.insert(i);
  for( int i = 0; i < n - 2; i++ ){
    int cur = *s.begin(); s.erase(s.begin());
    cout << cur + 1 << " " << v[i] + 1 << endl;
    if( --grau[v[i]] == 0 ) s.insert(v[i]);
  }
  cout << *s.begin() + 1 << " " << *s.rbegin() + 1 << endl;
}
