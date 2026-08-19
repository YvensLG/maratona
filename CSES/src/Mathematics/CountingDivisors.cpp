#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1000005;
int divi[MAX];
 
void calc(){
    divi[0] = 0;
    for(int i=1; i<=MAX; i++){
        for(int j=i; j<=MAX; j+=i){
            divi[j] ++;
        }
    }
}
 
void solve(){
    int x; cin >> x;
    cout << divi[x] << '\n';
    return;
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    calc();
    int t; cin >> t; while (t--)
    solve();
    return 0;
}