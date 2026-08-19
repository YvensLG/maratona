#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
#define M 1000000007
#define INF 2000000007
#define int long long
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef vector<double> vd;
typedef vector<int> vi;
typedef long long ll;
 
int divi[MAX];
 
int fexp(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % M;
		y >>= 1;
		x = (x * x) % M;
	}
	return ret;
}
 
void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;
 
	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}
 
void solve() {
    int n; cin >> n;
    vi p(n + 1), mark(n + 1), ciclos;
    for(int i = 1; i <= n; i++) cin >> p[i];
    
    int tam = 0, at;
    for(int ini = 1; ini <= n; ini++) {
        if(mark[ini] == 1) continue;
        
        at = ini; tam = 0;
        while(mark[at] == 0) {
            tam++;
            mark[at] = 1;
            at = p[at];
        }
        ciclos.push_back(tam);
    }
    
    crivo(MAX - 1);
    unordered_map<int, int> max_primos;
    for(auto c : ciclos) {
        while(c != 1) {
            int p = divi[c], count = 0;
            while(c % p == 0) {
                c /= p;
                count++;
            }
            max_primos[p] = max(max_primos[p], count);
        }
    }
    
    int ans = 1; 
    for(auto x : max_primos) {
        ans = (ans * fexp(x.first, x.second)) % M; 
    }
    
    cout << ans << '\n';
}
 
signed main() {
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}