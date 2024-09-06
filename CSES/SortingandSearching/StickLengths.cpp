#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define pb push_back
#define ll long long int
#define int long long
const int MOD = 1e9 + 7, MAX = 1e6 + 5, n = 10;
 
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    if(n == 1){
        cout << "0\n";
        return 0;
    }
    int p[n], soma = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        soma += p[i];
    }
    sort(p, p+n);
    int minimo = soma;
    for(int i = 0; i <= n/2; i++){
        soma -= 2*p[i];
        minimo = min(soma - (n - 2*(i + 1)) * p[i + 1], minimo);
    }
 
    for(int i = n/2 + 1; i < n - 1; i++){
        soma -= 2*p[i];
        minimo = min(soma - (n - 2*(i + 1)) * p[i], minimo);
    }
 
    cout << minimo << '\n';
}