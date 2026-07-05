#include <bits/stdc++.h>
 
#define int long long
#define pb push_back
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

/**
 * Author: someone on Codeforces
 * Date: 2017-03-14
 * Source: folklore
 * Description: A short self-balancing tree. It acts as a
 *  sequential container with log-time splits/joins, and
 *  is easy to augment with additional data.
 * Time: $O(\log N)$
 * Status: stress-tested
 */

struct Node {
	Node *l = 0, *r = 0;
	int val, y, c = 1;
	Node(int val) : val(val), y(rand()) {}
	void recalc();
};

int cnt(Node* n) { return n ? n->c : 0; }
void Node::recalc() { c = cnt(l) + cnt(r) + 1; }

template<class F> void each(Node* n, F f) {
	if (n) { each(n->l, f); f(n->val); each(n->r, f); }
}

pair<Node*, Node*> split(Node* n, int k) {
	if (!n) return {};
	if (cnt(n->l) >= k) { // "n->val >= k" for lower_bound(k)
		auto [L,R] = split(n->l, k);
		n->l = R;
		n->recalc();
		return {L, n};
	} else {
		auto [L,R] = split(n->r,k - cnt(n->l) - 1); // and just "k"
		n->r = L;
		n->recalc();
		return {n, R};
	}
}

Node* merge(Node* l, Node* r) {
	if (!l) return r;
	if (!r) return l;
	if (l->y > r->y) {
		l->r = merge(l->r, r);
		return l->recalc(), l;
	} else {
		r->l = merge(l, r->l);
		return r->recalc(), r;
	}
}

Node* ins(Node* t, Node* n, int pos) {
	auto [l,r] = split(t, pos);
	return merge(merge(l, n), r);
}

// Example application: move the range [l, r) to index k
void move(Node*& t, int l, int r, int k) {
	Node *a, *b, *c;
	tie(a,b) = split(t, l); tie(b,c) = split(b, r - l);
	if (k <= l) t = merge(ins(a, b, k), c);
	else t = merge(a, ins(c, b, k - r));
}

void solve(){
    
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}