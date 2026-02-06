#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef unsigned long long ull;

ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}

bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n-1), d  = n >> s;
    
    for (ull a: A) {
        ull p = modpow(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a %n && i--)
            p = modmul(p, p, n);
        if (p != n - 1 && i != s) return 0;
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<ull> primes;
    for (ull i = 2; i <= 1e6; i++) {
        if (isPrime(i) && isPrime(i * i + 4)) {
            primes.push_back(i * i + 4);
        }
    }

    int t; cin >> t;
    while (t--) {
        ull l, r; cin >> l >> r;

        auto ub = upper_bound(primes.begin(), primes.end(), r);
        auto lb = lower_bound(primes.begin(), primes.end(), l);

        cout << (ub - lb) << "\n";
    }

    return 0;
}