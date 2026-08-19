#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 100000000 
#define all(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef pair<int, int> pii;
 
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>  
 
bool comp(pii a, pii b){
    if(a.F < b.F) return 1;
    else if(a.F == b.F){
        return a.S > b.S;
    }
    return 0;
}
 
void solve() {
    int n; cin >> n;
    pair<int, int> v[n];
    map<pii, int> mapa;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v[i] = {a, b};
        mapa[v[i]] = i;
    }
    sort(v, v + n, comp);
 
    ordered_set s1;
    int contido[n];
 
    for(int i = 0; i < n; i++){
        contido[i] =  i - s1.order_of_key(v[i].second);
        s1.insert(v[i].second);
    }
 
    ordered_set s2;
    int contem[n];
 
    for(int i = n - 1; i >= 0; i--){
        contem[i] =  s2.order_of_key(v[i].second + 1);
        s2.insert(v[i].second);
    }
 
    int transf[n];
 
    for(int i = 0; i < n; i++){
        transf[mapa[v[i]]] = i;
    }
 
    for(int i = 0; i < n; i++) contem[transf[i]] == 0 ?  cout << 0 << ' ' : cout <<  1 << ' ';
    cout << '\n';
    for(int i = 0; i < n; i++) contido[transf[i]] == 0 ? cout << 0 << ' ' : cout << 1 << ' ';
    cout << '\n';
 
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t; cin >> t; while(t--)
    solve();
 
    return 0;
}