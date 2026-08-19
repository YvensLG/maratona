#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define int long long
 
using namespace std;
 
void solve(){
	int n; cin >> n;
	set<int> px;
	set<int> py;
	for(int i = 0; i < n; i++){
		int x1, y1; cin >> x1 >> y1;
		// Chebyshev distance		
		int x = x1 + y1;
		int y = x1 - y1;
 
		px.insert(x);
		py.insert(y);
		int ansx = *px.rbegin() - *px.begin();
		int ansy = *py.rbegin() - *py.begin();
		cout << max(ansx, ansy) << '\n';
	}
}
 
signed main() { _
    solve();
    return 0;
}