#include <bits/stdc++.h>
#define int long long

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 998244353;
const int MAX = 35;

int n, ans = 0;
vector<int> divs;
vector<int> fact(MAX);

void bt(int idx, int sobra, int sum, int sz) {
    if (sobra == 1) {
        ans += (fact[sz] * sum) % MOD;
        ans += (fact[sz + 1] * (sum + 1)) % MOD;
        ans %= MOD;
        return;
    }
    
    for (int i = idx; i < divs.size(); i++) {
        if (divs[i] > sobra) break;

		if (divs[i] * divs[i] > sobra) {
            sum = (sum + sobra) % MOD;
            sz++;

			ans += (fact[sz] * sum) % MOD;
			ans += (fact[sz + 1] * (sum + 1)) % MOD;
			ans %= MOD;
        	return;
        }
		
        if (sobra % divs[i] == 0) {
            bt(i + 1, sobra / divs[i], (sum + divs[i]) % MOD, sz + 1);
        }
    }
}

void calc() {
	fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void solve() {
	cin >> n;

	if(n == 1) {
		cout << "1\n";
		return;
	}

	for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
        }
    }
	for(int i = divs.size() - 1; i >= 0; i--) {
		if(divs[i] * divs[i] != n)
			divs.push_back(n / divs[i]);
	}
	divs.push_back(n);

    bt(0, n, 0, 0);

    cout << ans << "\n";
}

signed main() { _
	calc();
    solve();
}