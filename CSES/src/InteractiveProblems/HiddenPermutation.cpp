#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
 
bool comparator(int a, int b)
{
	cout << "? " << a << ' ' << b << endl;
	string ans;
    cin >> ans;
    if(ans == "YES")
        return true;
    else
        return false;
}
 
void solve() {
    int n; cin >> n;
    vector<int> lista(n);
    for(int i = 1; i <= n; i++) lista[i - 1] = i;
    stable_sort(lista.begin(), lista.end(), comparator);
 
    vector<int> p(n+1);
    for(int i = 0; i < n; i++){
        int pos = lista[i];
        p[pos] = i+1;
    }
 
    cout << "! ";
    for(int i = 1; i <= n; i++){
        cout << p[i] << ' ';
    }
    cout << '\n';
}
 
signed main() { _
    // int t; cin >> t; while(t--)
    solve();
}