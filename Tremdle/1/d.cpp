#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

void solve()
{
  int n, m; cin >> n >> m;
  set<int> matching;
  vector<int> ans;
  
  for(int i = 1; i <= m; i++)
  {
    int a, b; cin >> a >> b;
    if(matching.find(a) == matching.end() && matching.find(b) == matching.end())
    {
      matching.insert(a);
      matching.insert(b);
      ans.push_back(i);
    }
  }
  if(matching.size() >= 2 * n) {
    cout << "Matching\n";
    for(int i = 0; i < n; i++)
    {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
  else {
    cout << "IndSet\n";
    int count = 0;
    for(int i = 1; i <= 3 * n; i++)
    {
      if(matching.find(i) == matching.end())
      {
        count ++;
        cout << i << ' ';
      }
      if(count == n)
      {
        cout << '\n';
        break;
      }
    }
  }
}


signed main() { _
    int t; cin >> t; while(t--) solve();
    return 0;
}