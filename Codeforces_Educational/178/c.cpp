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
    string s; cin >> s;
    int a = 0, b = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'A') a++;
        else b++;
    }
    if(s[n - 1] == 'B' && b >= 2) cout << "Bob\n";
    else if(s[n - 1] == 'B') cout << "Alice\n";
    else if(s[0] == 'A') cout << "Alice\n";
    else if(s[n - 2] == 'A') cout << "Alice\n";
    else cout << "Bob\n";
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}