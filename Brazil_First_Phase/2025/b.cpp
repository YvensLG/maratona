#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int) x.size()
#define rep(i,a,b) for(int i = a; i < b; i++)
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
typedef vector<int> vi;
const int MAX = 1'000'100;

int divi[MAX];
pii cong[MAX];

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	ll x, y, g = euclid(m, n, x, y);
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

vi pi(const vi& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

vi match(const vi& s, const vi& pat) {
    vi aux;
    for(auto x : pat) aux.push_back(x);
    aux.push_back(-1);
    for(auto x : s) aux.push_back(x);
	vi p = pi(aux), res;
	rep(i,sz(p)-sz(s),sz(p))
		if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
	return res;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), p(n + 1);

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) cin >> p[i];

    vector<int> vis(n + 1);
    vector<pii> eq;

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        vector<int> aux;
        int x = i; 
        while(!vis[x]) {
            vis[x] = 1;
            aux.push_back(x);
            x = p[x];
        }

        vector<int> p1;
        vector<int> p2;

        for(int i = 0; i < sz(aux); i++) {
            p1.push_back(a[aux[i]]);
            p2.push_back(b[aux[i]]);
        }
        for(int i = 0; i < sz(aux); i++) {
            p1.push_back(a[aux[i]]);
        }

        vi ans = match(p1, p2);
        if(sz(ans) == 0) {
            cout << "IMPOSSIVEL\n";
            return;
        }
        else if(sz(ans) == 1) {
            int mod = sz(p2);
            int val = -ans[0]; val %= mod; val = (val + mod) % mod;
            eq.push_back({val, mod});
        }
        else {
            int mod = ans[1] - ans[0];
            int val = -ans[0]; val %= mod; val = (val + mod) % mod;
            eq.push_back({val, mod});
        }
    }

    for(auto [x, mod] : eq) {
        if(mod <= 1) continue;

        int aux = mod;

        while(mod > 1) {
            int d = divi[mod], pot = 1;
            while(mod % d == 0) {
                mod /= d;
                pot *= d;
            }

            if(cong[d] == make_pair(0LL, 0LL)) {
                cong[d] = {x % pot, pot};
            }
            else {
                auto [x0, pot0] = cong[d];
                int x1 = x, pot1 = pot;
                if(pot0 > pot1) {
                    swap(pot0, pot1);
                    swap(x0, x1);
                }

                if(x0 % pot0 != x1 % pot0) {
                    cout << "IMPOSSIVEL\n";
                    return;
                }

                cong[d] = {x1 % pot1, pot1};
            }
        }
    }

    int x = 0, md = 1;
    for(int p = 0; p < MAX; p++) {
        if(cong[p] == make_pair(0LL, 0LL)) continue;
        x = crt(x, md, cong[p].first, cong[p].second);
        md = cong[p].second * md;
        if(x > 1000000000) {
            cout << "DEMAIS";
            return;
        }
        if(md > 1000000000) {
            break;
        }
    }

    for(int p = 0; p < MAX; p++) {
        if(cong[p] == make_pair(0LL, 0LL)) continue;
        if(x % cong[p].second == cong[p].first) continue;
        cout << "DEMAIS";
        return;
    }

    cout << x << '\n';
}

signed main() { _
    crivo(MAX - 1);
    solve();

    return 0;
}