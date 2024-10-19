#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 100000000 
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

void solve(){
	int n, q; cin >> n >> q;
	vector<int> pref(n + 1);
	int maxi = 0;
	for(int i = 1; i <= n; i++){
		int a; cin >> a;
		maxi = max(maxi, a);
		pref[i] = (i != maxi);
	}
	string s; cin >> s;
	s = "#" + s;
	// set<int> corte;
	int tot = 0;

	for(int i = 1; i < n; i++){
		if(s[i] == 'L' && s[i + 1] == 'R'){
			// corte.insert(i);
			tot += pref[i];
		}
	}

	for(int iii = 0; iii < q; iii++){
		int a; cin >> a;
		if(s[a] == 'L'){
			if(s[a - 1] == 'R' && s[a + 1] == 'R'){
				// corte.erase(a);
				tot -= pref[a];
			}
			else if(s[a - 1] == 'R' && s[a + 1] == 'L'){
			}
			else if(s[a - 1] == 'L' && s[a + 1] == 'R'){
				// corte.erase(a);
				tot -= pref[a];
				// corte.insert(a - 1);
				tot += pref[a - 1];
			}
			else if(s[a - 1] == 'L' && s[a + 1] == 'L'){
				// corte.insert(a - 1);
				tot += pref[a - 1];
			}
			s[a] = 'R';
		}
		else{
			if(s[a - 1] == 'R' && s[a + 1] == 'R'){
				// corte.insert(a);
				tot += pref[a];
			}
			else if(s[a - 1] == 'R' && s[a + 1] == 'L'){
			}
			else if(s[a - 1] == 'L' && s[a + 1] == 'R'){
				// corte.erase(a - 1);
				tot -= pref[a - 1];
				// corte.insert(a);
				tot += pref[a];
			}
			else if(s[a - 1] == 'L' && s[a + 1] == 'L'){
				// corte.erase(a - 1);
				tot -= pref[a - 1];
			}
			s[a] = 'L';
		}

		if(tot > 0) cout << "NO\n";
		else cout << "YES\n";
	}
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while(t--)
    solve();

    return 0;
}