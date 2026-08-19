#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;
 
void solve(){
    ll n; cin >> n;
    ll p[n], pot = 1, s = 0, dif = 20LL * inf;
 
    for(int i=0; i<n; i++){
        cin >> p[i];
        s += p[i];
        pot *= 2;
    }
 
    for(int i = 0; i < pot; i++){
        ll k = i;
        ll soma = 0, num = 0;
        while(k > 0){
            if(k%2 == 1){
                soma += p[num];
            }
            //cout << "num: " << num << '\n';
            k /= 2;
            num ++;
        }
        dif = min(dif, abs(2 * soma - s) );
    }
 
    cout << dif << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}