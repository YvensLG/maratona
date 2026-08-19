#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int M = 1e9 + 7;

struct BIT {
    vector<int> bit;
    int n;

    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = (ret + bit[r]) % M;
        return ret;
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = (bit[idx] + delta) % M;
    }
};
 
void solve() {
    int n; cin >> n;
    int ans = 0;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> aux = a;
    sort(aux.begin(), aux.end());
    aux.erase(unique(aux.begin(), aux.end()), aux.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(aux.begin(), aux.end(), a[i]) - aux.begin() + 1;
    }

    BIT bit(n + 1); bit.add(0, 1);

    for(int i = 0; i < n; i++) {
        int soma = bit.sum(a[i] - 1);
        ans += soma; ans %= M;
        bit.add(a[i], soma);
    }

    cout << ans << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}