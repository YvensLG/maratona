#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e6 + 10; 
const int mod = 1e9 + 7; 
const int b1 = 1'000'033; 
const int b2 = 500'000'071;

void solve() {
    int n, k; cin >> n >> k;
    int tot = 0;
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        if(a != i)
            tot += 2 * i;
    }

    cout << tot << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 

    solve();

    return 0; 
}
