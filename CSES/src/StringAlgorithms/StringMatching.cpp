#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e6 + 5, inf = 2e9, P = 1e9 + 7;
const ll  linf = 4e18, M = 2305843009213693951;

ll pot[maxn];

ll hsh(string s, int n){
    ll h = 0;
    for(int i = 0; i < n; i++){
        h = (h + (__int128 (pot[n - 1 - i]) * s[i]) % M) % M;
    }
    
    return h;
}

void calcpot(){
    pot[0] = 1;
    for(int i = 1; i < maxn; i++){
        pot[i] = (__int128 (pot[i - 1]) * P) % M;
    }
}

void solve() {
    string s, t; cin >> s >> t;
    int tot = 0;

    if(t.size() > s.size()){
        cout << "0\n";
        return;
    }
    
    ll at = hsh(s, t.size()), h = hsh(t, t.size());

    if(at == h) tot++;
    for(int i = 0; i < (int)s.size() - (int)t.size(); i++){
        at = ((__int128 (at) * pot[1] - __int128 (s[i]) * pot[t.size()] + s[i + t.size()]) % M + M) % M;
        if(at == h) tot++;
    }

    cout << tot << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    calcpot();
    solve();
    return 0;
}