#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
 
const ll mod = 1000000007;
 
ll pot(ll b, ll n){
    if(n == 0){
        return 1;
    }
    ll  k = pot(b, n/2);
 
    k = (k * k) % mod;
 
    if(n % 2 == 0){
        return k % mod;
    }
 
    else {
        return (b * k) % mod;
    }
}
 
int main(){
    ll a;
    cin >> a;
    cout << pot(2, a) << endl;
}