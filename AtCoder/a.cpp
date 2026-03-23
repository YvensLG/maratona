#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 998244353;
const int MAX = 2e5 + 5;

ll fexp(ll x, ll y, ll m) {
	ll ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % m;
		y >>= 1;
		x = (x * x) % m;
	}
	return ret;
}

int inv(int x) {
    x = x % M;
    return fexp(x, M - 2, M);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int sum_sq = 0, sum = 0, sum_two = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum_sq = (sum_sq + a[i] * a[i]) % M;
        sum = (sum + a[i]) % M;
    }

    if(n == 1) {
        cout << (a[0] * a[0]) % M << '\n';
        return;
    }

    sum_two = (sum * sum) % M;
    sum_two = (sum_two + M - sum_sq) % M;

    if (n == 2) {
        cout << (sum_sq - sum_two + M) % M << '\n';
        return;
    }

    int den = inv(3 * (n - 1));
    int term = (sum_two * 2 % M) * den % M;
    
    int ans = (sum_sq - term + M) % M;
    cout << ans << '\n';
}


signed main() { _
    solve();
    return 0;
}