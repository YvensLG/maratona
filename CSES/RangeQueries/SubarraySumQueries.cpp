#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;

typedef long long int ll;
 
const int MAXN = 2e5 + 5, INF = 2e9, M = 1e9 + 7;

struct node {
    ll best;
    ll bestprefix;
    ll bestsufix;
    ll sum;
};

node t[4*MAXN];

node combine(node a, node b) {
    node c;
    c.sum = a.sum + b.sum;
    c.best = max(max(a.best, b.best), a.bestsufix + b.bestprefix);
    c.bestprefix = max(a.bestprefix, a.sum + b.bestprefix);
    c.bestsufix = max(b.bestsufix, b.sum + a.bestsufix);
    return c;
}

void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v].sum = a[tl];
        t[v].best = max(a[tl], 0LL);
        t[v].bestprefix = max(a[tl], 0LL);
        t[v].bestsufix = max(a[tl], 0LL);
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        t[v].sum = new_val;
        t[v].best = max(new_val, 0LL);
        t[v].bestprefix = max(new_val, 0LL);
        t[v].bestsufix = max(new_val, 0LL);
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void solve(){
    ll n, m; cin >> n >> m;
    ll x[n + 1];
    x[0] = 0;
    for(ll i = 1; i <= n; i++) cin >> x[i];

    build(x, 1, 0, n);

    for(ll i = 0; i < m; i++)
    {
        ll k, a; cin >> k >> a;
        update(1, 0, n, k, a);
        cout << t[1].best << '\n';
    }

}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}