#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k = n / 2;
    if(k == 0){
        cout << 0 << "\n";
        return;
    }

    vector<int> x(k + 2, 0);
    for(int i = 1; i <= k; i++){
        x[i] = (a[i - 1] - a[n - i] + m) % m;
    }

    vector<int> y(k + 2, 0);
    int s = 0;
    for(int i = 1; i <= k + 1; i++){
        y[i] = (x[i] - x[i - 1] + m) % m;
        s += y[i];
    }
    s = s / m;
    
    sort(y.begin() + 1, y.end());

    int ans = 0;
    for(int i = 1; i < (int)y.size() - s; i++){
        ans += y[i];
    }

    cout << ans << "\n";
}

signed main() { _
    int t; cin >> t;
    while(t--) solve();
    return 0;
}