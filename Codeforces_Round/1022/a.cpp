#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second
#define pc __builtin_popcountll

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

int ask(int pos) {
    cout << "? " << pos << endl;
    cout.flush();
    int val;
    if (!(cin >> val)) exit(0);
    return val;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(k), q(k);
    for (int i = 0; i < k; i++) {
        p[i] = ask(i + 1);
    }
    for (int i = 0; i < k; i++) {
        q[i] = ask(n - k + 1 + i);
    }
    if (p == q) {
        cout << "! -1" << endl;
        cout.flush();
        return;
    }
    int r0 = 1;
    for (int i = 0; i < k; i++) {
        if (p[i] != q[i]) {
            r0 = i + 1;
            break;
        }
    }
    int F = (n - r0) / k;  
    int T = F - 1;         
    int low = 0, high = T;
    while (low < high) {
        int mid = (low + high) / 2;
        int x = ask(r0 + mid * k);
        int y = ask(r0 + (mid + 1) * k);
        if (x == y) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    int t_star = low;
    int a = r0 + t_star * k;
    int A_len = -1;
    for (int d = 0; d < k; d++) {
        int x = ask(a + d);
        int y = ask(a + d + k);
        if (x != y) {
            A_len = a + d;
            break;
        }
    }
    if (A_len == -1) {
        A_len = a;
    }
    int B_len = n - A_len;
    cout << "! " << A_len << " " << B_len << endl;
    cout.flush();
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}