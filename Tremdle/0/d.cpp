#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;

int lcm(int a, int b)
{
    int temp = __gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

vector<int> get_z(vector<int> s) {
	int n = s.size();
	vector<int> z(n, 0);

	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}

	return z;
}


void solve(){
	int n, m; cin >> n >> m;
    vector<vector<int>> difs(n + 1);
    vector<int> periodo(n + 1);
	int a, b;
	for(int i = 0; i < m; i++)
	{
	    cin >> a >> b;
	    if(a > b) swap(a, b);  
	    if(b - a > n / 2)
	    {
	        difs[a - b + n].push_back(b);
	    }
	    else if(b - a == n / 2)
	    {
	      difs[n / 2].push_back(a);
	      difs[n / 2].push_back(b);
	    }
	    else
	    {
	        difs[b - a].push_back(a);
	    }
	}
	
	vector<int> total;
	
	for(int i = 0; i < n; i++)
	{
	    if(difs[i].size() == 0) continue;
	    sort(all(difs[i]));
	    
	    vector<int> dist;
	    
	    for(int j = 0; j < (int)difs[i].size(); j++)
	    {
	        int at = difs[i][j];
	        int next = difs[i][0];
	        if(j + 1 < difs[i].size()) next = difs[i][j + 1];
	        dist.push_back((next - at + n) % n);
	    }
	    
	    int tot = 0;
	    int soma = 0;
	    bool flag = false;
	    vector<int> z = get_z(dist);
	    
	    for(int j = 0; j < z.size(); j++) {
	      if(j + z[j] == dist.size()) {
	        flag = true;
	        total.push_back(soma);
	        break;
	      }
	      soma += dist[j];
	    }
	    
	    if(!flag)
	    {
	      cout << "No\n";
	      return;
	    }
	}
	
	int result = 1;
  for(auto x : total)
  {
    result = lcm(result, x);
  }
	if(result < n) cout << "Yes\n";
	else cout << "No\n";
}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();

    return 0;
}