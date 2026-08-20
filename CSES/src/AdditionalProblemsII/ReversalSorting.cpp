#include <bits/stdc++.h>
using namespace std; 
 
#define FOR(i, a, b) for( int i = a; i < b; i++ )
#define bug(x) cout << #x << " " << x << endl;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
 
using vi = vector<int>; 
using ll = long long;
using pii = pair<int, int>; 
 
const int inf = 2e9; 
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
 
 
struct Node{
    Node *l = 0, *r = 0; 
    int val, mini, y, c = 1, flip = 0; 
    Node( int val = 0 ) : val(val), mini(val), y(rng()) {}
};
 
struct Treap{
    int cnt( Node *n ){ return n ? n->c : 0; }
    int val( Node *n ){ return n ? n->val : INT_MAX; }
    int mini( Node *n ){ return n ? n->mini : INT_MAX; }
    void recalc( Node *n ){
        if( n->flip ){
            swap( n->l, n->r ); 
            if(n->l) n->l->flip ^= 1; 
            if(n->r) n->r->flip ^= 1; 
            n->flip = 0; 
        } 
        n->c = cnt(n->l) + cnt(n->r) + 1; 
        n->mini = min({ val(n), mini(n->l), mini(n->r) });
    }
 
    Node *rt = 0; 
 
    template<class F> 
    void each( Node *n, F f ){
        if(n){ each(n->l, f); f(n->val); each(n->r, f); }
    }
 
    pair<Node*, Node*> split( Node* n, int k ){
        if(!n) return {};
        recalc(n);
        if(cnt(n->l) >= k){
            auto [L, R] = split(n->l, k); 
            n->l = R; 
            recalc(n); 
            return {L, n};
        }
        auto [L, R] = split(n->r, k - cnt(n->l) - 1); 
        n->r = L; 
        recalc(n); 
        return {n, R};
    }
 
    Node *merge( Node *l, Node *r ){
        if( !l ) return r; 
        if( !r ) return l; 
 
        recalc(l); 
        recalc(r); 
 
        if( l->y > r->y ){
            l->r = merge(l->r, r); 
            return recalc(l), l; 
        }
        r->l = merge(l, r->l); 
        return recalc(r), r; 
    }
 
    Node* ins( Node *t, Node *n, int pos ){
        auto [l, r] = split(t, pos); 
        return merge(merge(l, n), r); 
    }
 
    int query( Node *n ){
        if(!n) return 0; 
        recalc(n);
 
        if( mini(n->l) < val(n) && mini(n->l) < mini(n->r) ) return query(n->l); 
        if( val(n) < mini(n->r) ) return cnt(n->l) + 1; 
        return cnt(n->l) + 1 + query(n->r); 
    }
 
    void update( Node *n ){
        if(n){ n->flip ^= 1; recalc(n); }
    }
 
    void move( Node *& t, int l, int r, int k ){
        Node *a, *b, *c; 
        tie(a, b) = split(t, l); tie(b, c) = split(b, r - l); 
        if( k <= l ) t = merge(ins(a, b, k), c); 
        else t = merge(a, ins(c, b, k - r)); 
    }
};
 
void solve(){
    int n; cin >> n; 
    Treap t; 
 
    FOR(i, 0, n){
        int x; cin >> x; 
        Node *n = new Node(x); 
        t.rt = t.merge(t.rt, n); 
    }
 
    cout << n << '\n'; 
    FOR(i, 0, n){
        int pos = t.query(t.rt); 
        cout << i + 1 << " " << i + pos << '\n'; 
        
        auto [a, b] = t.split(t.rt, pos); 
        t.update(a); 
        t.rt = t.merge(a, b); 
        t.rt = t.split(t.rt, 1).second; 
    }
}   
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve(); 
}