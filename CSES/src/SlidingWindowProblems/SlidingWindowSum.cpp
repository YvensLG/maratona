#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
 
#define int long long
 
void solve(){
	int n, k; cin >> n >> k;
	int x, a, b, c; cin >> x >> a >> b >> c;
	int first = x;
	int sum = 0, at = x;
	int ans = 0;
	for(int i = 0; i < k; i++)
	{
		sum += at;
		at = (at * a + b) % c;
	}
	ans ^= sum;
	for(int i = k; i < n; i++)
	{
		sum += at - first;
		at = (at * a + b) % c;
		first = (first * a + b) % c;
		ans ^= sum;
	}
	cout << ans << '\n';
}
 
signed main (){_
	solve();
}