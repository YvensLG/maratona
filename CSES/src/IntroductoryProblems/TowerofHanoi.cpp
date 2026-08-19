#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;
 
void hanoi(int n, int ini, int fim){
    if(n == 0) return;
    int mid = 6 - ini - fim;
 
    hanoi(n - 1, ini, mid);
    cout << ini << ' ' << fim << '\n';
    hanoi(n - 1, mid, fim);
}
 
void solve(){
    int n; cin >> n;
    int total = 1;
    for(int i = 0; i < n; i++) total *= 2;
    total --;
    cout << total << '\n';
    hanoi(n, 1, 3);
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}