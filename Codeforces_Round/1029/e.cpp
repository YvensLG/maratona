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
    vector<int> a(n + 1);
    vector<int> b(n + 1);

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    set<int> ap;
    int at = 0;
    if(a[n] == b[n])
    {
        cout << n << '\n';
        return;
    }

    for(int i = n - 1; i > 0; i--)
    {
        if(a[i] == a[i + 1] || b[i] == b[i + 1] || b[i] == a[i])
        {
            at = i; break;
        }
        if(ap.find(a[i]) != ap.end() || ap.find(b[i]) != ap.end())
        {
            at = i;
            break;
        }
        
        ap.insert(a[i + 1]);
        ap.insert(b[i + 1]);
    }

    cout << at << '\n';

}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}