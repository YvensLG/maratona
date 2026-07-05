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
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }
    for(int i = 0; i < n; i++) {
        int b; cin >> b; b--;
        if(a[b] != i) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main() { _
    solve();
}