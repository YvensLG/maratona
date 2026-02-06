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
    int a, b, c; cin >> a >> b >> c;
    int x = (a + b + c) / 3;
    if((a + b + c) % 3 != 0) cout << "NO\n";
    else if(a > x || b > x || c < x) cout << "NO\n";
    else cout << "YES\n";
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}