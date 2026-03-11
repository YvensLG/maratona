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
const int M = 1e9 + 7;
const int inv2 = (M + 1) / 2;
const int maxn = 400005;

ll fexp(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % M;
		y >>= 1;
		x = (x * x) % M;
	}
	return ret;
}

void solve(){
	int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> p(n + 1);

    int num = 0, den = 0, pot = 1;
    for(int i = 0; i < n; i++)
    {
        num = (num + a[n - i] * pot) % M;
        pot = ((pot * (-2)) % M + M) % M;
    }
    den = (1 - pot + M) % M;

    int ans = 0;

    for(int x = 1; x <= 3; x++)
    {
        p[1] = ((num * fexp(den, M - 2) % M) - (x * fexp(3, M - 2) % M) + M) % M;
        int minimo = p[1];
        for(int i = 2; i <= n; i++)
        {
            p[i] = a[i - 1] - 2 * p[i - 1] - x;
            minimo = min(minimo, p[i]);
        }

        if(p[1] != a[n] - 2 * p[n] - x) continue;
        
        ans = max(ans, a[1] - 2 * (p[1] - minimo) - (p[2] - minimo));
    }

    cout << ans << '\n';
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}