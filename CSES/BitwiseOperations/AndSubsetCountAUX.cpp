#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
void FST(vi& a, bool inv) {
    for (int n = sz(a), step = 1; step < n; step *= 2) {
        for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
            int &u = a[j], &v = a[j + step]; tie(u, v) =
            inv ? pii(v - u, u) : pii(v, u + v); // AND
        }
    }
}
vi conv(vi a, vi b) {
    FST(a, 0); FST(b, 0);
    rep(i,0,sz(a)) a[i] *= b[i];
    FST(a, 1); return a;
}
 
void solve(){
    vi a = {0, 0, 0, 0, 0, 0, 0, 1};
    vi a1 = {0, 1, 0, 0, 0, 0, 0, 1};
    vi a3 = {0, 0, 0, 1, 0, 0, 0, 1};
    vi a4 = {0, 0, 0, 0, 1, 0, 0, 1};

    FST(a, 0);
    FST(a1, 0);
    FST(a3, 0);
    FST(a4, 0);
    rep(i,0,sz(a)) a[i] *= a1[i];
    rep(i,0,sz(a)) a[i] *= a3[i];
    rep(i,0,sz(a)) a[i] *= a3[i];
    rep(i,0,sz(a)) a[i] *= a4[i];

    for(auto x : a) cout << x << ' ';
    cout << endl;
    
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}