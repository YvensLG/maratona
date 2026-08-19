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
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n, k; cin >> n >> k;
    vector<ll> v(n);
    ll base = 0;
    
    for(auto &x : v) {
        cin >> x;
        if(x < 0) base += x;
        x = abs(x);
    }
    sort(all(v));

    cout << base << ' '; k--;
    // (minimo, posicao minima)
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({base + v[0], 0});

    while(!pq.empty() && k--) {
        auto [at, pos] = pq.top(); pq.pop();
        cout << at << ' ';
        if(pos == n - 1) continue;
        pq.push({at - v[pos] + v[pos + 1], pos + 1});
        pq.push({at + v[pos + 1], pos + 1});
    }
    cout << '\n';

}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
