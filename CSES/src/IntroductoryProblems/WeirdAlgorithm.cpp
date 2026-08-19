#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1010, inf = 2e9, M = 1e9 + 7;
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t; cin >> t; while (t--)
    ll n; cin >> n;
    while(n != 1){
        cout << n << ' ';
        if(n % 2 == 0) n = n/2;
        else n = 3*n + 1;
    }
    cout << "1\n";
    return 0;
}