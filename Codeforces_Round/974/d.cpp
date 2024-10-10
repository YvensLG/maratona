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
	int n, d, k; cin >> n >> d >> k;
	vector<pii> job;
	vector<int> ini(n);
	vector<int> fim(n);
	
	for(int i = 0; i < k; i++){
		int a, b; cin >> a >> b;
		job.push_back({a - 1, b - 1});
		ini[a - 1] ++;
		fim[b - 1] ++;
	}

	sort(job.begin(), job.end());

	int at = 0;

	for(auto j : job){
		if(j.first < d) at ++;
		else break;
	}	

	int maximo = at;
	int resM = 0;
	int minimo = at;
	int resm = 0;

	for(int i = d; i < n; i++){
		at += ini[i];
		at -= fim[i - d];
		if(at > maximo){
			maximo = at;
			resM = i - d + 1;
		}
		if(at < minimo){
			minimo = at;
			resm = i - d + 1;
		}
	}

	cout << resM + 1 << ' ' << resm + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while(t--)
    solve();

    return 0;
}