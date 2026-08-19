#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e6+5, maxlogn = 20, maxpot = 1048576, inf = 2e9, M = 1e9 + 7;
 
int mobius[maxn], menorprimo[maxn], freq[maxn];
 
void calc_menorprimo(){
    for(int i=2; i<maxn; i++){
        if(menorprimo[i] != 0) continue;
 
        for(int j=i; j<maxn; j+=i){
            if(menorprimo[j] == 0) menorprimo[j] = i;
        }
    }
}
 
void calc_mobius(){
    for(int i=2; i<maxn; i++){
        if(menorprimo[i] == i){
            mobius[i] = -1;
            continue;
        }
 
        if(i % (menorprimo[i] * menorprimo[i]) == 0){
            mobius[i] = 0;
            continue;
        }
 
        mobius[i] = -mobius[i / menorprimo[i]];
    }
}
 
void solve() {
    ll n; cin >> n;
    ll x, maxX = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        freq[x] ++;
        maxX = max(x, maxX);
    }
 
    ll total = n * (n - 1) / 2;
    for(int i = 2; i <= maxX; i++){
        if(mobius[i] == 0) continue;
        ll d = 0;
        for(int j = i; j <= maxX; j+=i){
            d += freq[j];
        }
 
        total += mobius[i] * d * (d - 1) / 2;
    }
 
    cout << total << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    calc_menorprimo();
    calc_mobius();
    solve();
    return 0;
}