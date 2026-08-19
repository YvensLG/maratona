#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n; cin >> n;
    int x, cont = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x % 2 == 1) cont++;
    }
 
    if(cont > 0) cout << "first\n";
    else cout << "second\n";
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while(t--)
    solve();
    return 0;
}
