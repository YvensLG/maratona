#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
// {1, 2, ..., k} -> F contribui com i, S com k - i
// k-th = min(f_i, s_{k - i})
// se f_i > s_{k - i}
// i > j : f_j > f_i > s_{k - i} > s_{k - j}
// i < j : s_{k - j}, f_i > s_{k - i} > f_j
// logo, i é o maior valor tq f_{i} > s_{k - i}
 
// se s_{k - i} > f_{i}
// i > j : f_j, s_{k - i} > f_i > s{k - j}
// i < j : s_{k - j} > s_{k - i} > f_i > f_j
// logo, i é o menor valor tq s_{k - i} > f_{i}
 
void solve(){
    int n, k; cin >> n >> k;
	char c[2] = {'F', 'S'};
 
	// testa k = 1 ou 2
	cout << "F 1" << endl;
	int a; cin >> a;
	cout << "S 1" << endl;
	int b; cin >> b;
	
	if (k == 1) {
		cout << "! " << max(a, b) << endl;
		return; 
	}
	
	int r = min(k - 1, n), l = k - r;
 
	// edge cases garantem f_l > s_{k-l}  e  f_r < s_{k-r}
	for(int i = 0; i <= 1; i++)
	{
		cout << c[i] << " " << r << endl;
		cin >> a;
		cout << c[1 - i] << " " << l << endl;
		cin >> b;
		if (a > b) {
			a = -1;
			if(r + 1 <= n)
			{
				cout << c[i] << " " << r + 1 << endl;
				cin >> a;
			}
			cout << "! " << max(a, b) << endl;
			return;
		}
	}
 
	// f_l > s_{k-l}  e  f_r < s_{k-r}
	while (abs(r - l) > 1) {
		int mid = (l + r) / 2;
		cout << "F " << mid << endl;
		cin >> a;
		cout << "S " << k - mid << endl;
		cin >> b;
		if (a > b) {
			l = mid;
		} else {
			r = mid;
		}
	}
 
	// testa o melhor entre l e r
	cout << "S " << k - l << endl;
	cin >> b;
	cout << "F " << r << endl;
	cin >> a;
 
	cout << "! " << max(a, b) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}