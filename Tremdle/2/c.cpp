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
    int ganha = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] == 1 && ganha == 1) ganha = 0;
        else ganha = 1;
    }
    if(ganha == 0)
    {
        cout << "Second\n";
    }
    else
    {
        cout << "First\n";
    }

}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}