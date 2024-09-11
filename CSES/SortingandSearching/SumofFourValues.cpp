#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1010, inf = 2e9, M = 1e9 + 7;
 
// Sum of Two Values nos pares (i, j) do vetor original
void solve() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> v;
    
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v.pb({a, i});
    }

    if(n < 4){
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<pair<int, pair<int, int>>> pares;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            pares.push_back({v[i].first + v[j].first, {i, j}});
        }
    }
 
    sort(pares.begin(), pares.end());
 
    int fim = pares.size() - 1, ini = 0;
    int soma = 0;
 
    while(soma != x && fim != ini){
        soma = pares[fim].first + pares[ini].first;
        if(soma < x) ini++; 
        else if(soma > x) fim--;
        else{
            set<int> s;
            s.insert(pares[ini].second.first);
            s.insert(pares[ini].second.second);
            s.insert(pares[fim].second.first);
            s.insert(pares[fim].second.second);
            if(s.size() != 4){
                if(pares[ini].first == pares[ini + 1].first){
                    ini ++;
                }
                else{
                    fim --;
                }
                soma = -1;
            }
        }
    }
 
    if(soma == x) cout << pares[ini].second.first + 1 << ' ' << pares[ini].second.second + 1 << ' ' <<
                          pares[fim].second.first + 1 << ' ' << pares[fim].second.second + 1 << '\n';
    else cout << "IMPOSSIBLE\n";
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}