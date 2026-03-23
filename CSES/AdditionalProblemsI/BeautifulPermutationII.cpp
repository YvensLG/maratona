#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
#define int long long

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);

    if(n == 1) cout << "1\n";
    else if(n <= 3) cout << "NO SOLUTION\n";
    else {
        int i = 0;
        for(i = 0; 5 * i + 8 < n; i++) {
            v[5 * i + 0] = 1 + 5 * i;     
            v[5 * i + 1] = 3 + 5 * i;     
            v[5 * i + 2] = 5 + 5 * i;     
            v[5 * i + 3] = 2 + 5 * i;     
            v[5 * i + 4] = 4 + 5 * i;     
        }

        if(n % 5 == 4) {
            v[5 * i + 0] = 5 * i + 2;
            v[5 * i + 1] = 5 * i + 4;
            v[5 * i + 2] = 5 * i + 1;
            v[5 * i + 3] = 5 * i + 3; 
        }

        if(n % 5 == 0) {
            v[5 * i + 0] = 5 * i + 1;
            v[5 * i + 1] = 5 * i + 3;
            v[5 * i + 2] = 5 * i + 5;
            v[5 * i + 3] = 5 * i + 2; 
            v[5 * i + 4] = 5 * i + 4; 
        }

        if(n % 5 == 1) {
            v[5 * i + 0] = 5 * i + 1;
            v[5 * i + 1] = 5 * i + 3;
            v[5 * i + 2] = 5 * i + 5;
            v[5 * i + 3] = 5 * i + 2; 
            v[5 * i + 4] = 5 * i + 4; 
            v[5 * i + 5] = 5 * i + 6; 
        }

        if(n % 5 == 2) {
            v[5 * i + 0] = 5 * i + 1;
            v[5 * i + 1] = 5 * i + 3;
            v[5 * i + 2] = 5 * i + 5;
            v[5 * i + 3] = 5 * i + 2; 
            v[5 * i + 4] = 5 * i + 6; 
            v[5 * i + 5] = 5 * i + 4; 
            v[5 * i + 6] = 5 * i + 7; 
        }

        if(n % 5 == 3) {
            v[5 * i + 0] = 5 * i + 1;
            v[5 * i + 1] = 5 * i + 3;
            v[5 * i + 2] = 5 * i + 5;
            v[5 * i + 3] = 5 * i + 2; 
            v[5 * i + 4] = 5 * i + 6; 
            v[5 * i + 5] = 5 * i + 8; 
            v[5 * i + 6] = 5 * i + 4; 
            v[5 * i + 7] = 5 * i + 7; 
        }

        for(auto x : v) cout << x << ' ';
        cout << '\n';
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}