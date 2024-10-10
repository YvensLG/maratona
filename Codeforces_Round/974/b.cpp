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
	int n, k; cin >> n >> k;
	if(n <= k){
		if(n % 4 == 1 || n % 4 == 2) cout << "NO\n";
		else cout << "YES\n";
	}
	else{
		int impar = 0;
		if(k % 4 == 1 || k % 4 == 2) impar = 1;
		else impar = 0;

		if((n - k) % 2 == 1) impar = (impar + k) % 2;

		if(impar == 1) cout << "NO\n";
		else cout << "YES\n";
	}
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while(t--)
    solve();

    return 0;
}