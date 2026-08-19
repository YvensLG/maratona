#include <bits/stdc++.h>
using namespace std; 
 
/*
    [1, k] ordenado -> inserir k + 1
 
    flippar [1, k + 1] -> ans1
    flippar [1, k + 1] -> ans2
 
    ans1 = X + k*(k - 1)/2 + menores
    ans2 = X + k - menores
 
    ans1 - ans2 = 2*menores + k*(k - 1)/2 - k
    menores = (ans1 - ans2 - k*(k - 3)/2)/2
*/
 
int query( int l, int r ){
    cout << l << " " << r << '\n'; cout.flush();
    int ans; cin >> ans; 
    if( ans == 0 ) exit(0); 
    return ans; 
}
 
void solve(){
    int n; cin >> n; 
    if( n == 1 ) query( 1, 1 ); 
    for( int i = 1; i < n; i++ ){
        int x1 = query(1, i + 1); 
        int x2 = query(1, i + 1);
 
        int smaller = (x1 - x2 - i*(i - 3)/2)/2;
 
        if( smaller < i ){
            query( smaller + 1, i ); 
            query( smaller + 1, i + 1 );
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve(); 
}
