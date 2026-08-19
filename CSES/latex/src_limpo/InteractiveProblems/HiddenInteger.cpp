const int MAXN = 1e9;

void solve(){
  int l = 0, r = MAXN;

  while(r - l > 1)
  {
    int m = (l + r) / 2;
    cout << "? " << m << endl;
    string ans; cin >> ans;
    if(ans == "YES")
      l = m;
    else
      r = m;
  }
  cout << "! " << r << '\n';
}
