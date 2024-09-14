#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1010, inf = 2e9, M = 1e9 + 7;
 
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> v;
    
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v.pb(a);
    }

    map<int, int> rep;

    int p1 = 0, p2 = 0;
    ll cont = 0;
    int at = 0;
    int dis = 0;

    while(p1 < n || p2 < n){
        if(p2 == n || (rep[v[p2]] == 0 && dis >= k)){
            rep[v[p1]] --;
            if(rep[v[p1]] == 0) dis --;
            cont += at;
            at --;
            p1 ++;
        }
        else if(rep[v[p2]] == 0 && dis < k){
            rep[v[p2]] = 1;
            dis ++;
            at ++;
            p2 ++;
        }
        else{
            rep[v[p2]] ++;
            at ++;
            p2 ++;
        }
    }

    cout << cont << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}