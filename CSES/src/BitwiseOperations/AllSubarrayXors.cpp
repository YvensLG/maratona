#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long 

using namespace std;
 
const int maxn = 1048576;
const int mod = 998244353;

int inverse(int x, int mod) {
	return x == 1 ? 1 : mod - mod / x * inverse(mod % x, mod) % mod;
}

void xormul(vector<int> a, vector<int> b, vector<int> &c) {
	int m = (int) a.size();
	c.resize(m);
	for (int n = m / 2; n > 0; n /= 2)
		for (int i = 0; i < m; i += 2 * n)
			for (int j = 0; j < n; j++) {
				int x = a[i + j], y = a[i + j + n];
				a[i + j] = (x + y) % mod;
				a[i + j + n] = (x - y + mod) % mod;
			}
	for (int n = m / 2; n > 0; n /= 2)
		for (int i = 0; i < m; i += 2 * n)
			for (int j = 0; j < n; j++) {
				int x = b[i + j], y = b[i + j + n];
				b[i + j] = (x + y) % mod;
				b[i + j + n] = (x - y + mod) % mod;
			}
	for (int i = 0; i < m; i++)
		c[i] = a[i] * b[i] % mod;
	for (int n = 1; n < m; n *= 2)
		for (int i = 0; i < m; i += 2 * n)
			for (int j = 0; j < n; j++) {
				int x = c[i + j], y = c[i + j + n];
				c[i + j] = (x + y) % mod;
				c[i + j + n] = (x - y + mod) % mod;
			}
	int mrev = inverse(m, mod);
	for (int i = 0; i < m; i++)
		c[i] = c[i] * mrev % mod;
}

void solve(){
    int n; cin >> n;

    vector<int> A(maxn, 0);
    vector<int> pref(n + 1, 0);
    A[0]++;
    for(int i = 1; i <= n; i++)
    {
        int a; cin >> a;
        pref[i] = a ^ pref[i - 1];
        A[pref[i]]++;
    }
    
    vector<int> B = A, C;
    xormul(A, B, C);

    vector<int> ans;

    if(C[0] > n + 1) ans.push_back(0);
    for(int i = 1; i < maxn; i++)
    {
        if(C[i] > 0) ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for(auto x : ans) cout << x << ' ';
    cout << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}