#include <bits/stdc++.h>
#define pb push_back
#define pc __builtin_popcount
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;
const int M = 1e9 + 7;
const int maxn = 55;
const double pi = 3.1415926535897932384626;

#define int long long

int fexp(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % M;
		y >>= 1;
		x = (x * x) % M;
	}
	return ret;
}

void solve() {
    int n; cin >> n;
    int sum = 0, quad = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        sum = (sum + a) % M;
        quad = (quad + a * a) % M;
    }
    int div = fexp((n * (n - 1)) % M, M - 2);
    sum = (sum * sum) % M;
    cout << ( (sum + M - quad) % M * div ) % M << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}