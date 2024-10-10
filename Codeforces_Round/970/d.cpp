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

#define int long long


void solve() {
    int n; cin >> n;
    string s;
    vector<int> p(n + 1), v, cnt(n + 1), res(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> p[i];
        cnt[i] = -1;
    }

    cin >> s;
    for(int i = 1; i <= n; i++){
        if(cnt[i] >= 0) continue;
        int contador = 0;
        v.clear();
        int at = i;
        do{
            v.push_back(at);
            if(s[at - 1] == '0') contador++;
            at = p[at];
        } while(at != i);
        for(auto x : v){
            cnt[x] = 0;
            res[x] = contador;
        }
    }

    for(int i = 1; i <= n; i++) cout << res[i] << ' ';
    cout << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}