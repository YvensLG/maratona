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
    int a, b; cin >> a >> b;
 
    if((a == 0 && b != 0) || (b == 0 && a != 0)){
        cout << "NO\n";
        return;
    }
    if(a == 0 && b == 0){
        cout << "YES\n";
        for(int i = 1; i <= n; i++) cout << i << ' ';
        cout << '\n';
        for(int i = 1; i <= n; i++) cout << i << ' ';
        cout << '\n';
        return;
    }
    if(a + b > n){
        cout << "NO\n";
        return;
    }
    if(b == 1){
        cout << "YES\n";
        for(int i = 1; i <= n; i++) cout << i << ' ';
        cout << '\n';
        cout << a + 1 << ' ';
        for(int i = 1; i <= a; i++) cout << i << ' ';
        for(int i = a + 2; i <= n; i++) cout << i << ' ';
        cout << '\n';
        return;
    }
    if(a == 1){
        swap(a, b);
        cout << "YES\n";
        cout << a + 1 << ' ';
        for(int i = 1; i <= a; i++) cout << i << ' ';
        for(int i = a + 2; i <= n; i++) cout << i << ' ';
        cout << '\n';
        for(int i = 1; i <= n; i++) cout << i << ' ';
        cout << '\n';
        return;
    }
 
    cout << "YES\n";
    for(int i = 1; i <= a; i++) cout << i << ' ';
    cout << a + b << ' ';
    for(int i = 1; i <= b - 1; i++) cout << i + a << ' ';
    for(int i = a + b + 1; i <= n; i++) cout << i << ' ';
    cout << '\n';
    
    cout << a << ' ';
    for(int i = 1; i <= a - 1; i++) cout << i << ' ';
    for(int i = 1; i <= b; i++) cout << i + a << ' ';
    for(int i = a + b + 1; i <= n; i++) cout << i << ' ';
    cout << '\n';
}
 
signed main() { _
    int t; cin >> t; while(t--)
    solve();
}