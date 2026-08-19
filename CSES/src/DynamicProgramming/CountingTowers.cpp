#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e6 + 5, inf = 2e9, M = 1e9 + 7;

int f[maxn];

void calc(){
    f[0] = 1; f[1] = 2;
    int s = 3;
    for(int i = 2; i < maxn; i++){
        f[i] = (7LL * f[i - 1] + (ll)(M - 2) * s) % M;
        s = (s + f[i]) % M; 
    }
}
 
void solve() {
    int n; cin >> n;
    cout << f[n] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    calc();
    int t; cin >> t; while (t--)
    solve();
    return 0;
}
