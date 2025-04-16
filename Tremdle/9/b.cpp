#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long

void solve() {
  int h, w, m; cin >> h >> w >> m;
  vector<pair<int, int>> alvos(m);
  vector<int> linhas (h + 1);
  vector<int> colunas(w + 1);
  for(int i = 0; i < m; i++)
  {
    cin >> alvos[i].first >> alvos[i].second;
    linhas [alvos[i].first ]++;
    colunas[alvos[i].second]++;
  }
  int maxlin = 0, maxcol = 0, totlin = 0, totcol = 0;
  
  for(auto x : linhas ) {
    if(x > maxlin)
    {
      maxlin = x;
      totlin = 1;
    }
    else if(x == maxlin)
    {
      totlin++;
    }
  }
  
  for(auto x : colunas ) {
    if(x > maxcol)
    {
      maxcol = x;
      totcol = 1;
    }
    else if(x == maxcol)
    {
      totcol++;
    }
  }
  
  int qtddmax = 0;
  for(auto x : alvos)
  {
    if(linhas[x.first] == maxlin && colunas[x.second] == maxcol)
    {
      qtddmax ++;
    }
  }
  
  if(qtddmax == totcol * totlin) cout << maxcol + maxlin - 1 << '\n';
  else cout << maxcol + maxlin << '\n';
}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();
}