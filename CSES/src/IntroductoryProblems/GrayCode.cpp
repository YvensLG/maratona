#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;
int v[26];
 
void printv(vector<int> v){
    for(int i=0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}
 
void solve(){
    int n; cin >> n;
    vector<int> v; v.pb(0); v.pb(1);
    int pot = 2;
 
    for(int i = 0; i < n - 1; i++){
        int tam = v.size();
        for(int j = tam - 1; j >= 0; j--){
            v.pb(v[j] + pot);
        }
        pot *= 2;
    }
 
    for(int i = 0; i < v.size(); i++){
        string s;
        for(int j = 0; j < n; j++){
            if(v[i] % 2 == 0) s.pb('0');
            if(v[i] % 2 == 1) s.pb('1');
            v[i] /= 2;
        }
        cout << s << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}