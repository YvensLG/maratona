#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 2e6+5;
int v[maxn];
 
void solve() {
    int n; int x; int result = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        x = x % 4;
        result ^= x;
    }
 
    if(result == 0) cout << "second\n";
    else cout << "first\n";
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while(t--) solve();
 
    return 0;
}