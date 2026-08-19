#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
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
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}