#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define int long long
#define pb push_back
 
const int maxn = 2e6+6, mod = 1e9+7;
int fat[2 * maxn], invfat[2 * maxn], catalan[maxn];
 
void calcfat(){
    fat[0] = 1;
    for(int i=1; i<maxn; i++){
        fat[i] = (fat[i-1] * i) % mod;
    }
}
 
int fexp(int n, int exp){
    if(exp == 0) return 1;
    if(exp == 1) return n;
    int x = fexp(n, exp / 2);
    x = (x * x) % mod;
    if(exp % 2 == 1){
        return (n * x) % mod;
    }
    return x;
}
 
int inv(int n){
    return fexp(n, mod-2);
}
 
void calcinvfat(){
    for(int i=0; i<maxn; i++){
        invfat[i] = inv(fat[i]);
    }
}
 
void calccatalan(){
    for(int i=0; i<maxn; i++){
        catalan[i] = (((fat[2*i] * invfat[i+1]) % mod) * invfat[i]) % mod;
    }
}
 
void solve() {
    int n; cin >> n;
    if(n % 2 == 1){
        cout << "0\n";
        return;
    }
 
    string s; cin >> s;
    int k = 0;
    for(auto x : s){
        if(x == '(') k ++;
        else if (x == ')') k --;
        if(k < 0){
            cout << "0\n";
            return;
        }
    }
 
    n = (n - s.size() - k) / 2;
    int fator = 1, soma = 0;
 
    for(int i = 0; k-2*i >= 0; i++){
        fator = (((fat[k-i] * invfat[i]) % mod) * invfat[k-2*i]) % mod;
 
        if(i % 2 == 1) fator = -fator;
        fator = (fator + mod) % mod;
        soma = (soma + (fator * catalan[n + k - i]) % mod ) % mod;
    }
 
    cout << soma << '\n';
}
 
int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    calcfat();
    calcinvfat();
    calccatalan();
    solve();
 
    return 0;
}