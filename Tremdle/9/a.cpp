#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  
  for(int i = 0; i < n; i++) cin >> a[i];
  
  sort(a.begin(), a.end());
  
  int sum = 0;
  int qtd = 0;
  
  for(auto x : a) 
  {
    if(x != 0 && x + sum != 0)
    {
      x += sum;
      sum += -x;
      qtd ++;
    }
  }
  
  cout << qtd << '\n';
}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();
}