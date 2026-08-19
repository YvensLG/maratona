#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

struct bint {
    static const int BASE = 1e9;
    vector<int> v;
    bool neg;

    bint() : neg(0) {}
    bint(int val) : bint() { *this = val; }
    bint(long long val) : bint() { *this = val; }

    void trim() {
        while (v.size() and v.back() == 0) v.pop_back();
        if (!v.size()) neg = 0;
    }

    bint& operator=(const bint& val) { v = val.v, neg = val.neg; return *this; }
    bint& operator=(long long val) {
        v.clear(), neg = 0;
        if (val < 0) neg = 1, val *= -1;
        for (; val; val /= BASE) v.push_back(val % BASE);
        return *this;
    }

    int cmp(const bint& r) const { 
        if (neg != r.neg) return neg ? -1 : 1;
        if (v.size() != r.v.size()) {
            int ret = v.size() < r.v.size() ? -1 : 1;
            return neg ? -ret : ret;
        }
        for (int i = int(v.size())-1; i >= 0; i--) {
            if (v[i] != r.v[i]) {
                int ret = v[i] < r.v[i] ? -1 : 1;
                return neg ? -ret : ret;
            }
        }
        return 0;
    }
    friend bool operator<(const bint& l, const bint& r) { return l.cmp(r) == -1; }
    friend bool operator>=(const bint& l, const bint& r) { return l.cmp(r) >= 0; }
    friend bool operator!=(const bint& l, const bint& r) { return l.cmp(r) != 0; }
    friend bool operator==(const bint& l, const bint& r) { return l.cmp(r) == 0; }

    friend bint operator-(bint val) {
        if (val != 0) val.neg ^= 1;
        return val;
    }

    bint& operator +=(const bint& r) {
        if (!r.v.size()) return *this;
        if (neg != r.neg) return *this -= -r;
        for (int i = 0, c = 0; i < r.v.size() or c; i++) {
            if (i == v.size()) v.push_back(0);
            v[i] += c + (i < r.v.size() ? r.v[i] : 0);
            if ((c = v[i] >= BASE)) v[i] -= BASE;
        }
        return *this;
    }
    friend bint operator+(bint a, const bint& b) { return a += b; }

    bint& operator -=(const bint& r) {
        if (!r.v.size()) return *this;
        if (neg != r.neg) return *this += -r;
        if ((!neg and *this < r) or (neg and r < *this)) {
            *this = r - *this;
            neg ^= 1;
            return *this;
        }
        for (int i = 0, c = 0; i < r.v.size() or c; i++) {
            v[i] -= c + (i < r.v.size() ? r.v[i] : 0);
            if ((c = v[i] < 0)) v[i] += BASE;
        }
        trim();
        return *this;
    }
    friend bint operator-(bint a, const bint& b) { return a -= b; }

    bint& operator *=(int val) {
        if (val < 0) val *= -1, neg ^= 1;
        for (int i = 0, c = 0; i < v.size() or c; i++) {
            if (i == v.size()) v.push_back(0);
            long long at = (long long) v[i] * val + c;
            v[i] = at % BASE;
            c = at / BASE;
        }
        trim();
        return *this;
    }

    bint& operator/=(int val) {
        if (val < 0) neg ^= 1, val *= -1;
        for (int i = int(v.size())-1, c = 0; i >= 0; i--) {
            long long at = v[i] + c * (long long) BASE;
            v[i] = at / val;
            c = at % val;
        }
        trim();
        return *this;
    }

    friend bint abs(bint val) {
        val.neg = 0;
        return val;
    }
    friend bint operator *(bint a, int b) { return a *= b; }
    friend bint operator /(bint a, int b) { return a /= b; }

    friend pair<bint, bint> divmod(const bint& a_, const bint& b_) { // O(n^2)
		if (a_ == 0) return {0, 0};
		int norm = BASE / (b_.v.back() + 1);
		bint a = abs(a_) * norm;
		bint b = abs(b_) * norm;
		bint q, r;
		for (int i = a.v.size() - 1; i >= 0; i--) {
			r *= BASE, r += a.v[i];
			long long upper = b.v.size() < r.v.size() ? r.v[b.v.size()] : 0;
			int lower = b.v.size() - 1 < r.v.size() ? r.v[b.v.size() - 1] : 0;
			int d = (upper * BASE + lower) / b.v.back();
			r -= b*d;
			while (r < 0) r += b, d--; // roda O(1) vezes
			q.v.push_back(d);
		}
		reverse(q.v.begin(), q.v.end());
		q.neg = a_.neg ^ b_.neg;
		r.neg = a_.neg;
		q.trim(), r.trim();
		return {q, r / norm};
	}
	bint operator/(const bint& val) { return divmod(*this, val).first; }
	bint& operator/=(const bint& val) { return *this = *this / val; }
    bint operator%(const bint& val) { return divmod(*this, val).second; }
	bint& operator%=(const bint& val) { return *this = *this % val; }
};
 
pair<int, int> prob(int ri, int rj) {
    int num = 0, den = 1;
    if(rj >= ri) {
        num = ri - 1;
        den = 2 * rj;
    }
    else {
        num = rj - 1 + 2 * ri - 2 * rj;
        den = 2 * ri;
    }
    return {num, den};
}

vector<int> calc_primes(int max) {
    vector<int> divi(max + 1);
    vector<int> primes;
    
    divi[1] = 1;
    for (int i = 2; i <= max; i++) {
        if (divi[i] == 0) divi[i] = i, primes.push_back(i);
        for (int j : primes) {
            if (j > divi[i] or i*j > max) break;
            divi[i*j] = j;
        }
    }

    return primes;
}

void solve() {
    int n; cin >> n;
    vector<int> r(n);
    for(auto &x : r) cin >> x;

    bint MMC = 1;
    auto primes = calc_primes(200);

    for(int p : primes) {
        int q = p;
        while(q * p <= 200) q *= p;
        MMC *= q;
    }

    bint NUM = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            auto [a, b] = prob(r[i], r[j]);
            NUM += (MMC / b) * a;
        }
    }

    NUM *= 1'000'000;
    bint ANS = NUM/MMC;
    bint res = NUM%MMC;

    res *= 2;
    int comp = res.cmp(MMC);

    if (comp > 0) ANS += bint(1);
    else if (comp == 0 && ANS.v[0] % 2 != 0) {
        ANS += bint(1);
    }

    ll final_ans = 0;
    if (ANS.v.size() > 0) final_ans += ANS.v[0];
    if (ANS.v.size() > 1) final_ans += 1LL * ANS.v[1] * bint::BASE;

    cout << final_ans / 1000000 << ".";
    string final_res = "";
    for(int i = 0; i < 6; i++) {
        final_res.push_back(final_ans % 10 + '0');
        final_ans /= 10;
    }
    reverse(final_res.begin(), final_res.end());
    cout << final_res << '\n';
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}