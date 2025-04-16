#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(), (v).end()

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k; 
vector<int> ans0, ans1;
vector<vector<pair<int, int>>> G;
vector<bool> mark;

void dfs(int at) {
  mark[at] = true;
  
  if(G[at].size() <= 1)
  {
    ans1[at] = 0;
    ans0[at] = 0;
  }
  
  vector<int> respostas; 
  int tot = 0;
  for (auto [f, w] : G[at]) {
    if(mark[f]) continue;
    dfs(f);
    respostas.push_back(max(ans1[f] + w - ans0[f], 0LL));
    tot += ans0[f];
  }
  sort(all(respostas));
  reverse(all(respostas));
  
  int soma = 0;
  for(int i = 0; i < min(k, (int)respostas.size()); i++) {
    soma += respostas[i];
  }
  ans0[at] = tot + soma;
  
  soma = 0;
  for(int i = 0; i < min(k - 1, (int)respostas.size()); i++) {
    soma += respostas[i];
  }
  ans1[at] = tot + soma;
}

void solve() {
  cin >> n >> k;
  
  ans0.clear(); ans1.clear(); G.clear(); mark.clear();
  ans0.resize(n + 1); ans1.resize(n + 1); G.resize(n + 1); mark.resize(n + 1, false);
  
  for(int i = 1; i < n; i++)
  {
    int u, v, w; cin >> u >> v >> w;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
  
  int root = 1;
  dfs(root);
  
  cout << ans0[1] << '\n';
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}