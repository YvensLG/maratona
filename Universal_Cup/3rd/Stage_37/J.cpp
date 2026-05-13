#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

// static char buf[450 << 20];
// void* operator new(size_t s) {
//     static size_t i = sizeof buf;
//     assert(s < i);
//     return (void*)&buf[i -= s];
// }
// void operator delete(void*) {}

const int inf = 1e9;

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        // assert(a < b);
        if (a == b) return inf;
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf;
    ll val = 0;
    Node(int lo,int hi):lo(lo),hi(hi){}
    Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = (l->val + r->val);
        }
        else val = v[lo];
    }
    ll query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return (l->query(L, R) + r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mset = x;
            val = (ll) x * (hi - lo);
        }
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = (l->val + r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
    }
};

struct SuffixArray {
    vi sa, lcp;
    SuffixArray(string s, int lim=256) {
        s.push_back(0); int n = sz(s), k = 0, a, b;
        vi x(all(s)), y(n), ws(max(n, lim));
        sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            rep(i,0,n) ws[x[i]]++;
            rep(i,1,lim) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
                (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        for (int i = 0, j; i < n - 1; lcp[x[i++]] = k)
            for (k && k--, j = sa[x[i] - 1];
                s[i + k] == s[j + k]; k++);
    }
};

void solve() {
    string s; cin >> s;

    SuffixArray sa(s);
    RMQ rmq(sa.lcp);
    
    vi pos(sz(sa.sa));
    for (int i = 0; i < sz(sa.sa); ++i) {
        pos[sa.sa[i]] = i;
    }
        
    ll base = 0;
    for (int i = 1; i < sz(sa.sa); ++i) {
        base += sz(s) - (sa.sa[i] + sa.lcp[i]);
    }

    vi ini(sz(sa.sa));
    for (int i = 1; i < sz(sa.sa); ++i) {
        ini[sa.sa[i]] = sz(s) - (sa.sa[i] + sa.lcp[i]);
    }
    
    Node*tr = new Node(ini, 0, sz(ini));

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        --l, --r;
        int p = pos[l];
        int ps = r - l;
        if (ps < (tr->query(p, p + 1))) {
            int sl = 0, sr = p;
            while (sl < sr) {
                int mid = (sl + sr) / 2;
                if (rmq.query(mid + 1, p + 1) < ps) {
                    sl = mid + 1;
                } else {
                    sr = mid;
                }
            }
            int L = sl;
            sl = p, sr = sz(sa.sa) - 1;
            while (sl < sr) {
                int mid = (sl + sr + 1) / 2;
                if (rmq.query(p + 1, mid + 1) < ps) {
                    sr = mid - 1;
                } else {
                    sl = mid;
                }
            }
            int R = sl;
            tr->set(L, L + 1, ps);
            tr->set(L + 1, R + 1, 0);
        }
        ll x = (tr->query(0, sz(sa.sa)));
        ll ans = base - x;
        cout << ans << " ";
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}
