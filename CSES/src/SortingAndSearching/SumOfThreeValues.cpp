#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1010, inf = 2e9, M = 1e9 + 7;
vector<pair<int, int>> v;

pair<int, int> two_values(int ini, int fim, int x) {
    int soma = 0;

    do{
        soma = v[fim].first + v[ini].first;
        if(soma < x) ini++;
        else if(soma > x) fim--;
    } while(soma != x && fim != ini);
 
    if(soma == x){
        return {v[ini].second + 1, v[fim].second + 1};
    }

    else return {-1, -1};
}

void solve() {
    int n, x; cin >> n >> x;
    
    for(int i=0; i<n; i++){
        int a; cin >> a;
        v.pb({a, i});
    }

    if(n < 3){
        cout << "IMPOSSIBLE\n";
        return;
    }
 
    sort(v.begin(), v.end());
 
    for(int i = 0; i < n - 2; i++){
        pair<int, int> p = two_values(i + 1, n - 1, x - v[i].first);
        if(p.first != -1){
            cout << v[i].second + 1 << ' ' << p.first << ' ' << p.second << '\n';
            return;
        } 
    }

    cout << "IMPOSSIBLE\n";
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}