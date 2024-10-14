#include <bits/stdc++.h>
#define pb push_back
#define pc __builtin_popcount
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;
const int M = 1e9 + 7;
const int maxn = 55;
const double pi = 3.1415926535897932384626;

void solve() {
    int n, k; cin >> n >> k;
    map<int, int> s;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        s[a]++;
    }
    vector<pii> v;
    for(auto it = s.begin(); it != s.end(); ++it){
        v.pb({it -> first, it -> second});
    }

    int at = v[0].S;
    int maximo = at;
    int ini = 0;
    for(int fim = 1; fim < v.size(); fim++){
        if(v[fim].F - v[fim - 1].F == 1 && fim - ini + 1 <= k){
            at += v[fim].S;
        }
        else if(v[fim].F - v[fim - 1].F == 1 && fim - ini + 1 > k){
            at += v[fim].S;
            at -= v[ini].S;
            ini++;
        }
        else{
            ini = fim;
            at = v[ini].S;
        }
        maximo = max(at, maximo);
    }

    cout << maximo << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}