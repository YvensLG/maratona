#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e5+5, inf = 2e9, M = 1e9 + 7;
 
void solve(){
    int n, a, b; cin >> n;
    vector<tuple<int, int, int>> v;
    for(int i = 1; i <= n; i++){
        cin >> a >> b;
        v.push_back({a, 0, i});
        v.push_back({b, 1, i});
    }
    sort(all(v));
    queue<int> fila;
    vector<int> result(n + 1);
    int cont = 0;

    for(auto x : v){
        if(get<1>(x) == 0){
            if(fila.empty()){
                cont++;
                result[get<2>(x)] = cont;
            }
            else{
                result[get<2>(x)] = fila.front();
                fila.pop();
            }
        }
        else{
            fila.push(result[get<2>(x)]);
        }
    }

    cout << cont << '\n';
    for(int i = 1; i <=n; i++) cout << result[i] << ' ';
    cout << '\n';

}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}