#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;
const int MAX = 2e5+5;

int nxt[MAX][26];

void solve(){
	string s; cin >> s;
    string t; cin >> t;

    int n = s.size(), m = t.size();

    for(int j = 0; j < 26; j++) nxt[n][j] = -1;

    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < 26; j++) nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i] - 'a'] = i;
    }

    ll tot = 0;
    for(int i = 0; i < n; i++) {
        int at = nxt[i][t[0] - 'a'];
        for(int j = 1; j < m; j++) {
            if(at == -1) break;
            at = nxt[at + 1][t[j] - 'a'];
        }
        if(at == -1) tot += n - i;
        else tot += at - i;
    }

    cout << tot << '\n';
}

signed main() { _
    int t = 1;
    // cin >> t;
    while(t--)
    solve();

    return 0;
}