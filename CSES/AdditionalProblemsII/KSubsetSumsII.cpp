#include <bits/stdc++.h>
#define pb push_back

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll> tll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<ll> v(n);
    ll base = 0;
    
    for(auto &x : v) {
        cin >> x;
    }
    sort(all(v));

    for(int i = 0; i < m; i++) base += v[i];

    // (minimo possivel, ficha que ta mexendo, pos_atual, pos_final)
    priority_queue<tll, vector<tll>, greater<tll>> pq;

    pq.push({base, m - 1, m - 1, n - 1});
    vector<ll> ans;

    while(!pq.empty() && ans.size() < k) {
        auto [mini, at, pos, fim] = pq.top(); pq.pop();
        ans.push_back(mini);
        
        if(pos + 1 <= fim)
            pq.push({mini - v[pos] + v[pos + 1], at, pos + 1, fim});
        
        if(at >= 1 && at <= pos - 1)
            pq.push({mini - v[at - 1] + v[at], at - 1, at, pos - 1});
    }

    for(auto x : ans) cout << x << ' ';
    cout << '\n';

}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
