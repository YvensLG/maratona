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
	int x, y, k; cin >> x >> y >> k;
    pii a, b, c, d;
    if(x <= y){
        a = {0, y};
        b = {x, y - x};
        c = {0, y - x};
        d = {x, y};
    }
    else{
        a = {0, y};
        b = {y, 0};
        c = {0, 0};
        d = {y, y};
    }
    cout << a.F << ' ' << a. S << ' ' <<  b.F << ' ' << b.S << '\n';
    cout << c.F << ' ' << c. S << ' ' <<  d.F << ' ' << d.S << '\n';
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}