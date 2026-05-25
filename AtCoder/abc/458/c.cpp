#include <bits/stdc++.h>
#define int long long

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    string s; cin >> s;
    int n = s.size(); 
    int tot = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] != 'C') continue;
        int l = i + 1, r = n - i;
        tot += min(r, l);
    }

    cout << tot << '\n';
}

signed main() { _
    solve();
}