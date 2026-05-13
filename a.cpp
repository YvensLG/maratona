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
const int inv2 = 5e8 + 4;
const int maxn = 400005;
 
void solve(){
	int n, p, s; cin >> n >> p >> s;
	vector<pair<int, int>> pneu(3);
	for(int i = 0; i < 3; i++) cin >> pneu[i].first;
	for(int i = 0; i < 3; i++) cin >> pneu[i].second;
 
	int best = LINF;
 
	for(int i = 0; i <= s + 1; i++) {
	for(int j = i; j <= s + 1; j++) {
		int voltas = n, time = 0, mini, den;
 
		mini = min(voltas, pneu[0].second * (i)); den = pneu[0].second;
		time += pneu[0].first * mini;
		time += ((mini + den - 1) / den) * p; 
		voltas -= mini;
 
		mini = min(voltas, pneu[1].second * (j - i)); den = pneu[1].second;
		time += pneu[1].first * mini;
		time += ((mini + den - 1) / den) * p; 
		voltas -= mini;
 
		mini = min(voltas, pneu[2].second * (s + 1 - j)); den = pneu[2].second;
		time += pneu[2].first * mini;
		time += ((mini + den - 1) / den) * p; 
		voltas -= mini;
 
		time -= p;
 
		if(voltas > 0) continue;
		best = min(time, best);
	}
	}
 
	cout << best << '\n';
}
 
signed main() { _
    solve();
    return 0;
}
