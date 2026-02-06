#include <bits/stdc++.h>

using namespace std;
#define int long long

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LINF = 1000000000000000000;
const int MAX = 6010, MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vi v(n);

    for(int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));
    v.push_back(LINF);

    int count = 0;

    
    vector<int> pot2(MAX), pot3(MAX); pot2[0] = 1; pot3[0] = 1;

    
    for(int i = 1; i < MAX; i++) {
        pot2[i] = (pot2[i - 1] * 2) % MOD;
        pot3[i] = (pot3[i - 1] * 3) % MOD;
    }
    
    int i = 0;
    for(int j = i + 1; j < n; j++) {
        for(int k = j + 1; k < n; k++) {
            int min1 = v[i], min2 = v[j], min3 = v[k];

            auto itp = lower_bound(all(v), min1 + min2);
            int p = itp - v.begin();
            auto itq = lower_bound(all(v), min1 + min3);
            int q = itq - v.begin();
            auto itr = lower_bound(all(v), min2 + min3);
            int r = itr - v.begin();
            
            if(r <= n - 1 || p <= k) {
                continue;
            }
            count += ((pot2[max(k - j - 1, 0LL)] * pot3[max(p - 1 - k, 0LL)]) % MOD * pot2[max(q - p, 0LL)]) % MOD;
            count %= MOD;
            // cout << i << ' ' << j << ' ' << k << '\n';
            // cout << p << ' ' << q << ' ' << r << '\n';
            // cout << count << '\n'; 

        }
    }

    cout << count << '\n';

    return 0;
}