#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 2e5;

bool checker(int x, int n) {
    x = abs(x);
    if(x > n * (n + 1) / 2 - 1) return 0;
    if(x == n * (n + 1) / 2 - 3) return 0;

    if(x % 2 == 1 && ((n % 4) == 1 || (n % 4) == 2)) return 0;
    if(x % 2 == 0 && ((n % 4) == 0 || (n % 4) == 3)) return 0;

    return 1;
}

int find_n(int x) {
    if(x == 0) return 5;
    x = abs(x);
    int n = max(((sqrt(4LL * x + 1LL) - (long double)1) / 2.0) - 5, (long double)0);

    while(!checker(x, n)) {
        n++;
    }

    return n;
}

int ans[MAX];
void calc_ans(int x, int n) {
    if(n == 2) {
        ans[n] = x;
        return;
    }

    if(checker(x - n, n - 1)) {
        ans[n] = n;
        calc_ans(x - n, n - 1);
    }
    else {
        ans[n] = -n;
        calc_ans(x + n, n - 1);
    }
}

void solve() {
    int x; cin >> x;
    if(x == 1) {
        cout << 1 << '\n' << 1 << '\n';
        return;
    }
    x--;
    ans[1] = 1;

    int n = find_n(x);
    calc_ans(x, n);

    cout << n << '\n';
    cout << 1;
    for(int i = 2; i <= n; i++) {
        if(ans[i] > 0) {
            cout << '+' << ans[i];
        }
        else {
            cout << ans[i];
        }
    }
    cout << '\n';
}

signed main() {
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
