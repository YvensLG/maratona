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
typedef tuple<ll, ll, ll, ll> qll;
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
 
    // (minimo possivel, quem está movendo, pos atual, limite do movimento)
    priority_queue<qll, vector<qll>, greater<qll>> pq;
    pq.push({base, k - 1, k - 1, n - 1});
 
    vector<ll> ans;
 
    while(!pq.empty() && ans.size() < k) {
        auto [at, ind, pos, lim] = pq.top(); pq.pop();
        ans.push_back(at);

        if(pos + 1 <= lim)
            pq.push({at - v[pos] + v[pos + 1], ind, pos + 1, lim});
        if(ind > 0)
            pq.push({at, ind - 1, ind - 1, pos - 1});
    }
    for(auto x : ans) cout << x << ' ';
    cout << '\n';
 
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}