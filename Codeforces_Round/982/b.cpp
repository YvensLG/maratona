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
	int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int ans = LINF;

    for(int i = 0; i < n; i++){
        int tot = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] > v[i]) tot++;
        }
        ans = min(ans, tot);
    }

    cout << ans << '\n';
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}