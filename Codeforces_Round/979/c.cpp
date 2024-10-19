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
	string s; cin >> s;
	if(s[0] == '1' or s[n-1] == '1'){
		cout << "YES\n";
	}
	else{
		int at = 0;
		bool flag = false;
		for(int i = 0; i < n; i++){
			if(s[i] == '1') at++;
			else{
				if(at >= 2) flag = true;
				at = 0;
			}
		}
		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while(t--)
    solve();

    return 0;
}