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
    int p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p, p + n);
 
    int at = 0;
 
    for(int i = 0; i < n; i++){
        if(at >= p[i] - 1) at += p[i];
        else continue;
    }
 
    cout << at+1 << '\n';
}