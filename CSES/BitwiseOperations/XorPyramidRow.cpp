#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

int bin_v2(int n, int k) {
	return pc(k) + pc(n - k) - pc(n);
}

void solve(){
	int n, k; cin >> n >> k;
	int shift = n - k;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	for(int i = 1 << 30; i > 0; i >>= 1) {
		if((i & shift) == 0) continue;

		vector<int> aux(n - i);
		for(int j = 0; j < n - i; j++) {
            aux[j] = v[j] ^ v[j + i];
        }

		v = aux;
		n = aux.size();
	}

	for(auto x : v) cout << x << ' '; cout << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}