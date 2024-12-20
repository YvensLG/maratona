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
	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	int tot = 0;
	for(int i = 1; i <= (n + 1) / 2; i++){
		if(a[i] == a[n - i + 1]){
			int x = a[i];
			if(i <= n / 2 and (a[i + 1] == x or a[n - i] == x)) tot++;
			if(i > 1 and (a[i - 1] == x or a[n - i + 2] == x)) tot++;
			// cout << i << ' ' << tot << '\n';
		}
	}
	cout << tot << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while(t--)
    solve();

    return 0;
}