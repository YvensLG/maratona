using ll = long long;

int main(){
  int n, k; cin >> n >> k;
  vector<int> v(n);
  map<int, int> mp;
  for( int &x : v ){
    cin >> x;
    mp[x] = 1;
  }

  int cont = 1;
  for( auto &[key, val] : mp ) val = cont++;

  vector<int> bit(cont);

  auto update = [&]( int id, int val ){
    for( int i = id; i < (int)bit.size(); i += i&-i) bit[i] += val;
  };

  auto query = [&]( int id ){
    int sum = 0;
    for( int i = id; i > 0; i -= i&-i ) sum += bit[i];
    return sum;
  };

  ll inversions = 0;
  for( int i = 0; i < n; i++ ){
    v[i] = mp[v[i]];
    inversions += query(cont - 1) - query(v[i]);
    update(v[i], 1);
    if( i + 1 < k ) continue;
    cout << inversions << " ";
    inversions -= query(v[i - k + 1] - 1);
    update(v[i - k + 1], -1);
  }
  cout << endl;
}
