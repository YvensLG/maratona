#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;
char tab[10][10];
 
void solve(){
    ll k, soma = 0;
    cin >> k;
    ll cont = 1, pot = 1, ant = 0;
    while(soma < k){
        ant = soma;
        soma += 9 * pot * cont;
        pot *= 10;
        cont ++;
    }
    ll copia = k;
    ll dig = cont - 1;
    pot /= 10;
    copia -= ant + 1;
 
    //cout << dig << '\n';
    //cout << pot << '\n';
    //cout << copia << '\n';
 
    //cout << copia + pot << '\n';
 
    string s = to_string(copia/dig + pot);
 
    cout << s[copia % dig] << '\n';
 
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}