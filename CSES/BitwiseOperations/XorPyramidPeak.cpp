#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

int bin_v2(int n, int k) {
	return pc(k) + pc(n - k) - pc(n);
}

void solve(){
	int n; cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int a; cin >> a;
		if(bin_v2(n - 1, i) == 0) ans ^= a;
	}

	cout << ans << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}