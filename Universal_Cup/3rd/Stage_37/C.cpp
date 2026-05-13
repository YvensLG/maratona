#include <bits/stdc++.h>
using namespace std; 

const int maxn = 1e6 + 10; 

int a[maxn];

int tempo_ida( int n, int r, int p ){
    return (2*n - 1)*r + p; 
}

int tempo_volta( int n, int r, int p ){
    return (2*n - 1)*r + 2*n - p; 
}


void solve(){
    int n, m; cin >> n >> m;
    for( int i = 0; i < n; i++ ) cin >> a[i];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    int t; cin >> t; 
    while( t-- ) solve();
}