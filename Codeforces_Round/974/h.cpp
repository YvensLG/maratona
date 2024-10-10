#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 2000000000
#define LINF 4000000000000000000 
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll M = 1e18 + 3;
const int inv2 = 5e8 + 4;
const int maxn = 1e6+5;

ll pot[maxn];

ll sign(ll x){
	if(x < 0) return -1;
	else return 1;
}

ll has(ll x){
	return (__int128(M + sign(x)) * pot[abs(x)]) % M;
}

void solve(){
	int n, q; cin >> n >> q;
	vi v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	map<int, bool> a;

	for(int i = 0; i < n; i++){
		if(a[v[i]] == 1) {
			a[v[i]] = 0;
			v[i] = -v[i];
		}
		else{
			a[v[i]] = 1;
		}
	}

	vll prefix(n + 1);

	for(int i = 1; i <= n; i++){
		prefix[i] = (prefix[i - 1] + has(v[i - 1])) % M;
	}

	int l, r;
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		((prefix[r] + M - prefix[l - 1]) % M == 0) ? cout << "YES\n" : cout << "NO\n";
	}
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	pot[0] = 1;
	for(int i = 1; i < maxn; i++) pot[i] = (2 * pot[i - 1]) % M;

    int t; cin >> t; while(t--)
    solve();

    return 0;
}