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
    int qtdd = 0;
    vector<int> a(n);
    int minimo = INF;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] < minimo)
        {
            minimo = a[i];
            qtdd = 1;
        }
        else if (a[i] == minimo) qtdd++;
    }
    
    if(qtdd >= n/2 + 1) cout << "Bob\n";
    else cout << "Alice\n";
}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();

    return 0;
}