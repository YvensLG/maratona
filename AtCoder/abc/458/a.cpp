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
    int n; cin >> n;
    int m = s.size();

    for(int i = n; i < m - n; i++) cout << s[i];
    cout << '\n';
}

signed main() { _
    solve();
}