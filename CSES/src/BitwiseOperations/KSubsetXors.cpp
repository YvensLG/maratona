#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;

typedef long long int ll;
 
const int INF = 1e9 + 10, logINF = 30, logmax = 18;

// Gauss - Z2
//
// D eh dimensao do espaco vetorial
// add(v) - adiciona o vetor v na base (retorna se ele jah pertencia ao span da base)
// coord(v) - retorna as coordenadas (c) de v na base atual (basis^T.c = v)
// recover(v) - retorna as coordenadas de v nos vetores na ordem em que foram inseridos
// coord(v).first e recover(v).first - se v pertence ao span
//
// Complexidade:
// add, coord, recover: O(D^2 / 64)

template<int D> struct gauss_z2 {
	bitset<D> basis[D], keep[D];
	int rk, in;
	vector<int> id;
 
	gauss_z2 () : rk(0), in(-1), id(D, -1) {};
 
	bool add(bitset<D> v) {
		in++;
		bitset<D> k;
		for (int i = D - 1; i >= 0; i--) if (v[i]) {
			if (basis[i][i]) v ^= basis[i], k ^= keep[i];
			else {
				k[i] = true, id[i] = in, keep[i] = k;
				basis[i] = v, rk++;
				return true;
			}
		}
		return false;
	}
	pair<bool, bitset<D>> coord(bitset<D> v) {
		bitset<D> c;
		for (int i = D - 1; i >= 0; i--) if (v[i]) {
			if (basis[i][i]) v ^= basis[i], c[i] = true;
			else return {false, bitset<D>()};
		}
		return {true, c};
	}
	pair<bool, vector<int>> recover(bitset<D> v) {
		auto [span, bc] = coord(v);
		if (not span) return {false, {}};
		bitset<D> aux;
		for (int i = D - 1; i >= 0; i--) if (bc[i]) aux ^= keep[i];
		vector<int> oc;
		for (int i = D - 1; i >= 0; i--) if (aux[i]) oc.push_back(id[i]);
		return {true, oc};
	}
};

void solve(){
    int n, k; cin >> n >> k;
    gauss_z2<logINF> Gauss;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        bitset<logINF> v(a[i]);
        Gauss.add(v);
    }

    int tot = 0;

    vector<int> ans = {0};

    for (int i = 0; i < logINF; i++) {
        if (Gauss.basis[i].any()) {
            tot++;
            
            if(tot <= logmax)
            {
                int B = Gauss.basis[i].to_ullong();
                int sz = ans.size();
                for(int i = 0; i < sz; i++)
                    ans.push_back(ans[i] ^ B);
            }
        }
    }

    sort(ans.begin(), ans.end());
    int nul = n - tot;
    if(nul > 25) nul = 25;
    int mul = 1 << nul;
    for(auto x : ans)
    {
        for(int i = 0; i < mul; i++)
        {
            cout << x << ' ';
            k--;
            if(k == 0) {
                cout << '\n';
                return;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}