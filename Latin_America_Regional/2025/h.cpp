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
    int tot = 1; int at; cin >> at;

    for(int i = 1; i < n; i++) {
        int a; cin >> a;
        if(a > at) {
            at = a;
            tot++;
        }
    }

    cout << tot << '\n';
}

signed main() { _
    solve();
    return 0;
}