#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;
 
void printv(vector<int> v){
    for(int i=0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}
 
void solve(){
    int a, b;
    cin >> a >> b;
    if((2*b - a) % 3 == 0 && 2*b - a >= 0 && 2*a - b >= 0){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}