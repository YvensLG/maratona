#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long

const int MAX = 200005;

void solve() {
  string s; cin >> s; s = "0" + s;
  vector<pair<int, char>> ans;  
  for(int i = 0; i + 3 < s.size(); i++)
  {
    if(s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '1')
    {
      ans.push_back({s.size() - (i + 2) - 1, '-'});
      s[i + 2] = '1';
    }
  }
  
  for(int i = s.size() - 1; i >= 3; i--)
  {
    if(s[i] == '1' && s[i - 1] == '1' && s[i - 2] == '0' && s[i - 3] == '1')
    {
      ans.push_back({s.size() - (i - 2) - 1, '-'});
      s[i - 2] = '1';
    }
  }
  
  for(int i = 1; i < s.size() - 1; i++)
  {
    if(s[i] == '1' && s[i-1] == '0' && s[i+1] =='0')
    {
      ans.push_back({s.size() - i - 1, '+'});
      s[i] = '0';
    }
  }
  if(s[s.size() - 1] == '1' && s[s.size() - 2] == '0')
  {
    ans.push_back({0, '+'});
    s[s.size() - 1] = '0';
  }
  for(int i = 1; i < s.size() - 1; i++)
  {
    if(s[i] == '0' && s[i-1] == '1' && s[i+1] =='1')
    {
      ans.push_back({s.size() - i - 1, '-'});
      s[i] = '1';
    }
  }
  int count = 0;
  for(int i = s.size() - 1; i >= 0; i--)
  {
    if(s[i] == '1') count++;
    if(s[i] == '0' && count > 0) 
    {
      ans.push_back({s.size() - i - 1, '+'});
      ans.push_back({s.size() - i - 1 - count, '-'});
      count = 0;
    }
  }
  cout << ans.size() << '\n';
  for(auto x : ans) cout << x.second << "2^" << x.first << '\n';
}

signed main() { _
  solve();
}