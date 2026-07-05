#include <bits/stdc++.h>
using namespace std; 

#define int long long

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

// seja wk = c1 * c2 * ... * ck o número de elementos de profundidade k (w0 = 1)

// cada caminho valido tem duas partes
// raiz -> f1 -> f2 -> ... -> fk
// existe exatamente w_k desses 
// 
// pi -> p(i-1) -> ... -> p1 -> folha
// existe exatamente w_n desses

// se i + k < n : caminhos nunca se tocam
//
// (i, k) : ans += w_k * w_n
// total  : ans += w_k * w_n * (n - k) 

// senão: caminhos podem se tocar
// (i, k) : ans += w_k * w_n - w_n * w_k / w_{n - i}
// total  : ans += sum w_n * w_k * (1 - 1 / w_{n - i}) = w_n * w_k * (k - pref_inv_w[k])

// casos com multiplicidade (sem teleportes)
// ans -= w_n * (n - 1)

void solve(){
    int n; cin >> n;
    vector<int> c(n);
    for(auto &x : c) cin >> x;
    vector<int> w(n + 1); w[0] = 1;
    vector<int> pref_inv_w(n + 1); pref_inv_w[0] = 0;

    for(int i = 1; i <= n; i++) {
        w[i] = (c[i - 1] * w[i - 1]) % mod;
    }

    for(int i = 1; i <= n; i++) {
        pref_inv_w[i] = modpow(w[i], mod - 2);
        pref_inv_w[i] = (pref_inv_w[i] + pref_inv_w[i - 1]) % mod;
    }
    
    int ans = 0;

    for(int k = 0; k <= n; k++) {
        ans = (ans + (w[k] * w[n] % mod) * (n - k)) % mod;
    }

    for(int k = 0; k <= n; k++) {
        ans = (ans + (w[k] * w[n] % mod) * (k + mod - pref_inv_w[k]) % mod) % mod;
    }

    ans = (ans - w[n] * (n - 1) % mod + mod) % mod;

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve(); 
}