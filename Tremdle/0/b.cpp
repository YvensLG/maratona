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

void solve(){
	int n; cin >> n;
	string s;
	map<string, int> M;
	for(int i = 0; i < n; i++)
	{
	    cin >> s;
	    M[s] += 1;
	}
	for(auto x : M)
	{
	    if(x.second > n / 2)
	    {
	        cout << x.first << '\n';
	        return;
	    }
	}
	cout << "vixe\n";
	
}

signed main() { _
    solve();

    return 0;
}