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
	int n, r; cin >> n >> r;
	int sobra = 0;
	int total = 0;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		if(a % 2 == 1) sobra++;
		r -= a / 2;
		total += 2 * (a / 2);
	}

	if(sobra > r)
		cout << total + (2 * r - sobra) << '\n';
	else
		cout << total + sobra << '\n';

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while(t--)
    solve();

    return 0;
}