#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

const int LMAX = 18;
vector<int> v(1 << LMAX);

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> v[i];

	for (int i = 0; i < LMAX; i++) for (int mask = 0; mask < (1 << LMAX); mask++)
		if (mask>>i&1) v[mask] ^= v[mask^(1<<i)];
	
	for(int i = 0; i < n; i++) cout << v[i] << ' '; cout << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}