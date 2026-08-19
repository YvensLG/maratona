#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
 
using namespace std;
 
const int inf = 2e9 + 10;
 
// 4 1 3 5 6 7 2
// como 4 vem primeiro podemos colocar a nele
// a4a5a6a7 <= a1a2a3a4a5a6a7 e a5a6a7 <= a2a3a4a5a6a7
// então podemos fazer a1 = a4. Caso contrário, teriamos que colocar a1 = a4 + 1
// e analogo pra tds os outros
 
void solve(){
	int n; cin >> n;
	vector<int> a(n), pos(n + 2);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	pos[n + 1] = 0;
 
	char at = 'a';
	vector<char> s(n + 1, '$');
	for(int i = 0; i < n - 1; i++)  {
		if(pos[a[i] + 1] < pos[a[i + 1] + 1])  {
			s[a[i]] = at;
			s[a[i + 1]] = at;
		} 
		else {
			s[a[i]] = at;
			s[a[i + 1]] = at + 1;
			at++;
		}
	}
 
	for(int i = 1; i < s.size(); i++) {
		if(s[i] > 'z' || s[i] < 'a') {
			cout << -1 << '\n';
			return;
		}
	}
 
	for(int i = 1; i < s.size(); i++) {
		cout << s[i];
	}
	cout << '\n';
}
 
signed main() { _
    solve();
    return 0;
}