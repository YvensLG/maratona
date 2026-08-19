ordered_set s;

int main() {
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) s.insert(i);
  int at = 0;
  vector<int> v;

  while(s.size() != 0){
    at = (at + k) % s.size();
    auto it = s.find_by_order(at);
    v.push_back(*it);
    s.erase(it);
  }

  for(auto x : v) cout << x << ' ';
  cout << '\n';

}
