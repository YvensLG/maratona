#include <bits/stdc++.h>
using namespace std;
vector<int> a;

int main() {
  int n; cin >> n;
  int um = 0;
  for(int i = 0; i < n; i++) {
    int x; cin >> x; a.push_back(x);
    if(x == 1) um++;
  }
  
  if(um >= 1) {
    cout << n - um << '\n';
    return 0;
  }
  
  int mingap = n + 1;
  
  for(int i = 0; i < n; i++) {
    int mdc = 0;
    for(int j = i; j < n; j++) {
      mdc = __gcd(mdc, a[j]);
      if(mdc == 1) 
      {
        mingap = min(mingap, j - i + 1); 
      }
    }
  }
  
  if(mingap == n + 1)
    cout << -1 << '\n';
  else
    cout << mingap + n - 2 << '\n';
}