#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
    using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

#define int long long

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LINF = 1000000000000000000;
const int MAX = 600000;

int a[MAX];

struct Node {
    ll val;
    ll mini, maxi;
    ll qnt;
};

struct SegTree {
	Node seg[2*MAX], lazy[2*MAX];
	int n;

	void build(int n2, int* v) {
		n = n2;
        int at = LINF;
        for(int i = 0; i < n; i++) {
            if(v[i] == 0) {seg[n+i].mini = at; continue;}
            seg[n+i].mini = min(at, v[i]);
            at = seg[n+i].mini;
        }
        at = -LINF;
        for(int i = n-1; i >= 0; i--) {
            if(v[i] == 0) {seg[n+i].maxi = at; continue;}
            seg[n+i].maxi = max(at, v[i]);
            at = seg[n+i].maxi;
        }
        for (int i = 0; i < n; i++) {
            if(v[i] == 0) {seg[n+i].val = 0; continue;}
            seg[n+i].val = seg[n+i].maxi * seg[n+i].mini;
        }
        for(int i = 0; i < n; i++) {
            if(v[i] == 0) seg[n + i].qnt = 0;
            else seg[n + i].qnt = 1;
        }

		for (int i = n - 1; i; i--) seg[i] = junta(seg[2*i], seg[2*i+1]);
		for (int i = 0; i < 2*n; i++) {lazy[i].maxi = 0; lazy[i].mini = 0; lazy[i].val = 0; lazy[i].qnt = 0;}
	}

    Node junta(Node a, Node b) {
        Node c;
        if(a.qnt == 0 && b.qnt == 0) {
            c.mini = 0;
            c.maxi = 0;
            c.val = 0;
            c.qnt = 0;
            return c;
        }
        
        c.val = a.val + b.val;
        c.qnt = a.qnt + b.qnt;
        if(a.qnt == 0) {
            c.mini = b.mini;
            c.maxi = b.maxi;
            return c;
        }
        if(b.qnt == 0) {
            c.mini = a.mini;
            c.maxi = a.maxi;
            return c;
        }
        c.mini = a.mini + b.mini;
        c.maxi = a.maxi + b.maxi;
        return c;
    }

    void push(int v) {
        if(lazy[v].mini != 0) {
            for(auto x : {v * 2, v * 2 + 1}) {
                seg[x].mini = lazy[v].mini * seg[x].qnt;
                if(seg[x].qnt == 0 && x >= n) seg[x].mini = lazy[v].mini;
                if(seg[x].qnt != 0) seg[x].val  = lazy[v].mini * seg[x].maxi;
                lazy[x].mini = lazy[v].mini;
            }
        }
        if(lazy[v].maxi != 0) {
            for(auto x : {v * 2, v * 2 + 1}) {
                seg[x].maxi = lazy[v].maxi * seg[x].qnt;
                if(seg[x].qnt == 0 && x >= n) seg[x].maxi = lazy[v].maxi;
                if(seg[x].qnt != 0) seg[x].val  = lazy[v].maxi * seg[x].mini;
                lazy[x].maxi = lazy[v].maxi;
            }
        }
        lazy[v].mini = 0;
        lazy[v].maxi = 0;
    }

    Node query(int v, int tl, int tr, int l, int r) {
        Node res; res.val = 0; res.mini = 0; res.maxi = 0;
        if (l > r)
            return res;
        if (l == tl && tr == r)
            return seg[v];
        push(v);
        int tm = (tl + tr) / 2;

        res = query(v*2, tl, tm, l, min(r, tm));
        Node res1 = query(v*2+1, tm+1, tr, max(l, tm+1), r); 
        return junta(res, res1);
    }

    void push_all(int p) {
        vector<int> nodes;
        while(p >= 1) {
            nodes.push_back(p);
            p /= 2;
        }
        reverse(all(nodes));
        for(auto x : nodes) push(x);
    }

    void update_point(int p, int val) {
        push_all(n + p);
        int aux = n + p;
        seg[n + p].qnt = 1;


        while(aux >= 2) {
            aux /= 2;
            seg[aux].qnt += 1;
            if(seg[n + p].maxi != - LINF) seg[aux].maxi += seg[n + p].maxi;
            if(seg[n + p].mini !=   LINF) seg[aux].mini += seg[n + p].mini;
        }

        if(val < seg[n+p].mini) {
            int ini = n + p, fim = n + n - 1;
            push_all(fim);
            if(seg[fim].mini <= val) {
                while(ini < fim - 1) {
                    int mid = (ini + fim) / 2;
                    push_all(mid);
                    if(seg[mid].mini <= val) fim = mid;
                    else ini = mid;
                }
                fim--;
            }
            update_min(1, 0, n-1, p, fim - n, val);
        }

        if(val > seg[n+p].maxi) {   
            int ini = n, fim = n + p;
            push_all(ini);

            if(seg[ini].maxi >= val) {
                while(ini < fim - 1) {
                    int mid = (ini + fim) / 2;
                    push_all(mid);
                    if(seg[mid].maxi >= val) ini = mid;
                    else fim = mid;
                }
                ini++;
            }
            
            update_max(1, 0, n-1, ini - n, p, val);
        }

        push_all(n + p);

        if(seg[n+p].val == 0) {
            seg[n+p].val = seg[n+p].mini * seg[n+p].maxi;
            aux = n + p;
            while(aux >= 1) {
                aux /= 2;
                seg[aux].val += seg[n+p].val;
            }
        }
    }

    void update_min(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            seg[v].mini = addend * seg[v].qnt;
            if(seg[v].qnt == 0 && v >= n) seg[v].mini = addend;
            if(seg[v].qnt != 0) seg[v].val = seg[v].maxi * addend;
            lazy[v].mini = addend;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update_min(v*2, tl, tm, l, min(r, tm), addend);
            update_min(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
            seg[v] = junta(seg[v*2], seg[v*2+1]);
        }
    }

    void update_max(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            seg[v].maxi = addend * seg[v].qnt;
            if(seg[v].qnt == 0 && v >= n) seg[v].maxi = addend;
            if(seg[v].qnt != 0) seg[v].val = seg[v].mini * addend;
            lazy[v].maxi = addend;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update_max(v*2, tl, tm, l, min(r, tm), addend);
            update_max(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
            seg[v] = junta(seg[v*2], seg[v*2+1]);
        }
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

	int n, q; cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];
    ord_set<int> s;
    for(int i = 0; i < n; i++) s.insert(i); 
    
    vector<pair<int, int>> add;
    
    for(int i = 0; i < q; i++) {
        int t; cin >> t; t--;
        auto it = s.find_by_order(t);
        int real_pos = *it; s.erase(it);
        add.push_back({a[real_pos], real_pos});
        a[real_pos] = 0;
    }

    int aux = 1;
    while(aux < n) aux *= 2;
    n = aux;

    reverse(all(add));
    SegTree seg;
    seg.build(n, a);

    vector<int> ans;
    ans.push_back(seg.query(1, 0, n-1, 0, n-1).val);

    for(auto [val, pos] : add) 
    {
        seg.update_point(pos, val);
        ans.push_back(seg.query(1, 0, n-1, 0, n-1).val);
    }

    reverse(all(ans));
    for(auto x : ans) cout << x << ' ';
    cout << '\n';

    return 0;
}