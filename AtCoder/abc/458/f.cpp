#include <bits/stdc++.h>
#define int long long

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;

struct matrix : vector<vector<int>> {
	int n, m;

	void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cout << (*this)[i][j] << " ";
			cout << endl;
		}
	}

	matrix(int n_, int m_, bool ident = false) :
        vector<vector<int>>(n_, vector<int>(m_, 0)), n(n_), m(m_) {
		if (ident) {
			assert(n == m);
			for (int i = 0; i < n; i++) (*this)[i][i] = 1;
		}
	}
	matrix(const vector<vector<int>>& c) : vector<vector<int>>(c),
		n(c.size()), m(c[0].size()) {}

	matrix operator*(matrix& r) {
		assert(m == r.n);
		matrix M(n, r.m);
		for (int i = 0; i < n; i++) for (int k = 0; k < m; k++)
			for (int j = 0; j < r.m; j++) {
				int add = (*this)[i][k] * r[k][j];
				M[i][j] += add%MOD;
				if (M[i][j] >= MOD) M[i][j] -= MOD;
			}
		return M;
	}
	matrix operator^(ll e){
		matrix M(n, n, true), at = *this;
		while (e) {
			if (e&1) M = M*at;
			e >>= 1;
			at = at*at;
		}
		return M;
	}
};

void solve() {
    int n, k; cin >> n >> k;
    
    vector<string> bad(k);
    for(int i = 0; i < k; i++) {
        cin >> bad[i];
    }

    set<string> pref;
    pref.insert("");
    for(string s : bad) {
        string cur = "";
        for(char ch : s) {
            cur += ch;
            pref.insert(cur);
        }
    }

    vector<string> states;
    for(string p : pref) {
        bool ok = true;
        for(string b : bad) {
            if(p.find(b) != string::npos) {
                ok = false; 
                break;
            }
        }
        if(ok) states.pb(p);
    }

    int m = states.size();
    map<string, int> id;
    for(int i = 0; i < m; i++) {
        id[states[i]] = i;
    }

    matrix M(m, m);
    for(int i = 0; i < m; i++) {
        string u = states[i];
        
        for(char ch = 'a'; ch <= 'z'; ch++) {
            string w = u + ch;
            
            bool ok = true;
            for(string b : bad) {
                if(w.find(b) != string::npos) {
                    ok = false; 
                    break;
                }
            }
            if(!ok) continue;

            for(int len = w.size(); len >= 0; len--) {
                string suf = w.substr(w.size() - len);
                if(id.count(suf)) {
                    int v = id[suf];
                    M[i][v]++;
                    if(M[i][v] >= MOD) M[i][v] -= MOD;
                    break;
                }
            }
        }
    }

    matrix M_n = M^n;
    int ans = 0, srt = id[""];
    for(int j = 0; j < m; j++) {
        ans = (ans + M_n[srt][j]) % MOD;
    }
    
    cout << ans << '\n';
}

signed main() { _
    solve();
}