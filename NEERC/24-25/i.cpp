#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = (M + 1) / 2;
const int maxn = 400005;

void solve(){
	int n; cin >> n;
    vector<int> h(n); for(int i = 0; i < n; i++) cin >> h[i];
    vector<int> p(n); for(int i = 0; i < n; i++) cin >> p[i];

   vector<pii> a(n);
   bool ok = true;
   int mx = 0;
   for(int i=0; i<n; i++){
    a[i] = {p[i], p[i]-h[i]};
    mx = max(mx, p[i]-h[i]);
    if(p[i] - h[i] < 0) ok = false;
   }

   if(!ok){
    cout << -1 << endl;
    return;
   }

   sort(all(a));
   for(int i=0; i<n-1; i++){
    if(a[i].F == a[i+1].F){
        if(a[i].S != a[i+1].S) ok = false;
    }
    else if(a[i].S > a[i+1].S) ok = false;
   }

    if(!ok) cout << -1 << endl;
    else cout << mx << endl;
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}