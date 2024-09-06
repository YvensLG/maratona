#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
 
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