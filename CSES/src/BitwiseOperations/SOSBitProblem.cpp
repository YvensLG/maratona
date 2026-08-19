#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

const int LMAX = 20;
vector<int> sub(1 << LMAX);
vector<int> sup(1 << LMAX);

void solve(){
	int n; cin >> n; vector<int> v(n);
	for(int i = 0; i < n; i++) {
        cin >> v[i];
        sub[v[i]]++; sup[v[i]]++;
    }

	for (int i = 0; i < LMAX; i++) for (int mask = 0; mask < (1 << LMAX); mask++) {
		if (mask>>i&1)  sub[mask] += sub[mask^(1<<i)];
        if (~mask>>i&1) sup[mask] += sup[mask^(1<<i)];
    }
	
    int msk = (1 << LMAX) - 1;

	for(int i = 0; i < n; i++) {
        cout << sub[v[i]] << ' ' << sup[v[i]] << ' ' << n - sub[msk - v[i]] << '\n';
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}