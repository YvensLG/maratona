#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e5+5, inf = 2e9, M = 1e9 + 7;
const ll linf = 1e18;
 
void solve(){
    int n; cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    ll soma = 0;

    // se a soma > 2 * maior, tem como reorganizar para todo mundo ler o mais rápido possível

    for(int i = 0; i < n; i++){
        soma += a[i];
    }

    if(soma >= 2 * a[0]) cout << soma << '\n';
    else cout << 2 * a[0] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}