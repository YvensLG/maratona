#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LMAX = 18, MOD = 1e9 + 7;
vector<int> sub(1 << LMAX);
 
void FST(vi& a, bool inv) {
    for (int n = sz(a), step = 1; step < n; step *= 2) {
        for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
            int &u = a[j], &v = a[j + step]; tie(u, v) =
            inv ? pii((v - u + MOD) % MOD, u) : pii(v, (u + v) % MOD); // AND
        }
    }
}

ll pow(ll x, ll y, ll m) {
	ll ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % m;
		y >>= 1;
		x = (x * x) % m;
	}
	return ret;
}

/*
    a ideia pro FST eh pensar no polinomio prod(1 + x^a_i), mas com AND
    fica muito lento fazer os FST's, entao tem que ajeitar isso
    testando, da pra perceber que os FST's ficam iguais aos andares do triangulo de pascal em mod 2 (quem eh 0 fica 1, quem eh 1 fica 2)
    ai eh so calcular o produto com SOS dp e destransformar o FST
*/

void solve(){
    int n; cin >> n;
    vi a(n), sub(1 << LMAX);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i]; sub[a[i]]++;
    }

    for (int i = 0; i < LMAX; i++) for (int mask = 0; mask < (1 << LMAX); mask++) {
		if (~mask>>i&1) sub[mask] += sub[mask^(1<<i)];
    }

    vector<int> ans(1 << LMAX);
    for(int i = 0; i < sz(ans); i++) {
        ans[i] = pow(2, sub[i], MOD);  
    }
    reverse(all(ans));
    FST(ans, 1);

    for(int i = 0; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}